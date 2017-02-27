#!/usr/bin/perl -w
#
# Check SAP Availability and Response Time (Packet Round Trip Time)
# via SAP load balancing or directly to a specific application server
# based on SAP's RFCSDK
#
#
# Copyright (C) 2007 by Herbert Stadler
# email: hestadler@gmx.at

# License Information:
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License 
# along with this program; if not, see <http://www.gnu.org/licenses/>. 
#
#

############################################################################


use POSIX;
use strict;
use Getopt::Long;

use lib ".";
use lib "/usr/lib/nagios/plugins";
use lib "/usr/lib64/nagios/plugins";
use lib "/usr/local/nagios/libexec";

use utils qw(%ERRORS);

my ($opt_version,$opt_help,$opt_verbose);
my ($opt_timeout,$opt_license);
my ($opt_ashost,$opt_sysnr,$opt_r3name,$opt_mshost,$opt_group);
my ($opt_pingcnt,$opt_pingkb,$opt_pingint,$opt_warn,$opt_crit);
my ($PROGNAME,$REVISION);
my ($state,$msg);

use constant RFCPING		=> "/usr/local/rfcsdk/bin/rfcping";
use constant DEFAULT_TIMEOUT	=> 30;

# please modify if you havn't defined the rfcsdk libraries globally via 
# /etc/ld.so.conf (ldconfig)

$ENV{'LD_LIBRARY_PATH'}         =  '/usr/local/rfcsdk/lib/'; 


# return codes of rfcping command
my %RFCPING_RC = (
	0 =>		"OK",
	1 =>		"unrecognized parameter",
	2 =>		"Connect Failure: system down or wrong parameters",
	3 =>		"Timeout from call",
	4 =>		"Unspecified failure: logon/memory/codepage",
      255 =>		"General Error of calling rfcping (libraries missing?)",
   );



$ENV{'PATH'}='';
$ENV{'BASH_ENV'}=''; 
$ENV{'ENV'}='';
$PROGNAME = "check_sap_rfcping";
$REVISION = "1.3";

# checking commandline arguments
my $arg_status = check_args();
if ($arg_status){
  print "ERROR: some arguments wrong\n";
  exit $ERRORS{"UNKNOWN"};
}

# set alarmhandler for timeout handling
$SIG{'ALRM'} = sub {
  print ("ERROR: plugin timed out after $opt_timeout seconds \n");
  exit $ERRORS{"UNKNOWN"};
};

alarm($opt_timeout);

# check if command exists and executable flag is set
if ( ! -X RFCPING ) {
  printf ("ERROR: Command %s not found or not executable\n",RFCPING);
  exit $ERRORS{"UNKNOWN"};
}

my $p_rfcping_cmd="";
if ( defined ($opt_mshost)) {
  $p_rfcping_cmd.=RFCPING." r3name=".$opt_r3name." mshost=".$opt_mshost;
}
if ( defined ($opt_ashost)) {
  $p_rfcping_cmd.=RFCPING." sysnr=".$opt_sysnr." ashost=".$opt_ashost;
}

# and now the optional parameters
if (defined $opt_group) {
  $p_rfcping_cmd.=" group=".$opt_group;
}
if (defined $opt_pingcnt) {
  $p_rfcping_cmd.=" ping_cnt=".$opt_pingcnt;
}
if (defined $opt_pingkb) {
  $p_rfcping_cmd.=" ping_kb=".$opt_pingkb;
}
if (defined $opt_pingint) {
  $p_rfcping_cmd.=" ping_interval=".$opt_pingint;
}


printf ("\nRFCPING CMD: %s\n",$p_rfcping_cmd) 	if ($opt_verbose); 

if ( ! open(CMD, "$p_rfcping_cmd |") ) {
  print ("ERROR: can not execute $p_rfcping_cmd \n");
  exit $ERRORS{"UNKNOWN"};
}

# read command output
my @t_in=<CMD>;
close(CMD);
my $p_rc=$? >> 8;
printf ("\nRFCPING RC: %d\n",$p_rc)	 	if ($opt_verbose); 

if ($p_rc != 0){
  print ("ERROR: $RFCPING_RC{$p_rc}\n");
  exit $ERRORS{"CRITICAL"};
}

my $p_cmdout=join "", @t_in;
printf ("\nRFCPING OUTPUT:\n") 			if ($opt_verbose); 
printf ("%s",$p_cmdout) 			if ($opt_verbose); 

my ($p_minimum_ms,$p_maximum_ms,$p_average_ms,$p_destination);

# get round trip times
if ( $p_cmdout=~/.*\s+Minimum = (\d+)ms,\s+Maximum = (\d+)ms,\s+Average = (\d+)ms.*/ ) {
  $p_minimum_ms = $1;
  $p_maximum_ms = $2;
  $p_average_ms = $3;
}
printf ("Min: %d ms, Max: %d ms, Avg: %d ms\n",$p_minimum_ms,$p_maximum_ms,$p_average_ms)						if ($opt_verbose); 

# which SAP destination was it ?
if ( $p_cmdout=~/.*Destination\s+(\w+)$.*/ ) {
  $p_destination = $1;
}
printf ("Destination: %s\n",$p_destination)		if ($opt_verbose); 

# set default values for progexit
$msg = sprintf ("RFCPING OK - No Problems found, AvgRTT=%d ms (%s)",$p_average_ms,$p_destination);
$state = $ERRORS{'OK'};

# now we check the response time
if (( defined ($opt_warn)) && ( defined ($opt_crit))) {
  if ( $p_average_ms < $opt_warn ) {
    $msg = sprintf ("RFCPING OK - No Problems found, AvgRTT=%d ms (%s)",$p_average_ms,$p_destination);
    $state = $ERRORS{'OK'};
  } elsif ( $p_average_ms < $opt_crit ) {
    $msg = sprintf ("RFCPING WARNING - AvgRTT=%d ms (%s)",$p_average_ms,$p_destination);
    $state = $ERRORS{'WARNING'};
  } else {
    $msg = sprintf ("RFCPING CRITICAL - AvgRTT=%d ms (%s)",$p_average_ms,$p_destination);
    $state = $ERRORS{'CRITICAL'};
  }
}

# and now "over and out"

print "$msg\n";
exit $state;




#--------------------------------------------------------------------------#
# S U B R O U T I N E S                                                    #
#--------------------------------------------------------------------------#

sub check_args {
  Getopt::Long::Configure('bundling');
  GetOptions
	("V"   			=> \$opt_version,
	 "version"   		=> \$opt_version,
	 "L"   			=> \$opt_license, 
	 "license"   		=> \$opt_license, 
	 "v"   			=> \$opt_verbose, 
	 "verbose"   		=> \$opt_verbose, 
	 "h|?" 			=> \$opt_help,
	 "help"   		=> \$opt_help,
	 "t=i" 			=> \$opt_timeout, 
	 "timeout=i" 		=> \$opt_timeout, 
	 "r=s" 			=> \$opt_r3name, 
	 "r3name=s" 		=> \$opt_r3name, 
	 "m=s" 			=> \$opt_mshost, 
	 "mshost=s" 		=> \$opt_mshost, 
	 "a=s" 			=> \$opt_ashost, 
	 "ashost=s" 		=> \$opt_ashost, 
	 "g=s" 			=> \$opt_group, 
	 "group=s" 		=> \$opt_group, 
	 "s=i" 			=> \$opt_sysnr, 
	 "sysnr=i" 		=> \$opt_sysnr, 
	 "n=i" 			=> \$opt_pingcnt, 
	 "pingcnt=i" 		=> \$opt_pingcnt, 
	 "k=i" 			=> \$opt_pingkb, 
	 "pingkb=i" 		=> \$opt_pingkb, 
	 "i=i" 			=> \$opt_pingint, 
	 "pingint=i" 		=> \$opt_pingint, 
	 "w=i" 			=> \$opt_warn, 
	 "warn=i" 		=> \$opt_warn, 
	 "c=i" 			=> \$opt_crit, 
	 "crit=i" 		=> \$opt_crit, 
	 );

  if ($opt_license) {
    print_gpl($PROGNAME,$REVISION);
    exit $ERRORS{'OK'};
  }

  if ($opt_version) {
    print_revision($PROGNAME,$REVISION);
    exit $ERRORS{'OK'};
  }

  if ($opt_help) {
    print_help();
    exit $ERRORS{'OK'};
  }

  if ( (! defined($opt_mshost)) && (! defined($opt_ashost))){
    print "\nERROR: mshost or ashost not defined\n\n";
    print_usage();
    exit $ERRORS{'UNKNOWN'};
  }

  if ( defined($opt_mshost)){
    if ( ! defined($opt_r3name)){
      print "\nERROR: r3name not defined\n\n";
      print_usage();
      exit $ERRORS{'UNKNOWN'};
    }
  }
  if ( defined($opt_ashost)){
    if ( ! defined($opt_sysnr)){
      print "\nERROR: sysnr not defined\n\n";
      print_usage();
      exit $ERRORS{'UNKNOWN'};
    }
  }

  if ((defined ($opt_warn)) && (! defined ($opt_crit))) {
    print "\nERROR: parameter -c not defined\n\n";
    print_usage();
    exit $ERRORS{'UNKNOWN'};
  }

  if (( ! defined ($opt_warn)) && ( defined ($opt_crit))) {
    print "\nERROR: parameter -w not defined\n\n";
    print_usage();
    exit $ERRORS{'UNKNOWN'};
  }

  if (( defined ($opt_warn)) && ( defined ($opt_crit))) {
    if ( $opt_warn >= $opt_crit ) {
      print "\nERROR: parameter -w greater or equal parameter -c \n\n";
      print_usage();
      exit $ERRORS{'UNKNOWN'};
    }
  }

  unless (defined $opt_timeout) {
    $opt_timeout = DEFAULT_TIMEOUT;
  }

  return $ERRORS{'OK'};
}

sub print_usage {
  print "Usage: $PROGNAME [-h] [-L] [-t timeout] [-v] [-V] [-r r3name] [-s sysnr] [-n pingcount] [-i pinginterval] [-k pingKB] [-w warn] [-c crit] -m mshost | -a ashost \n";
}

sub print_help {
  print_revision($PROGNAME,$REVISION);
  print "\n";
  print_usage();
  print "\n";
  print "   Check SAP Availability and Response Time (Packet Round Trip Time)\n";
  print "   via SAP load balancing or directly to a specific application server.\n\n";
  print " -t (--timeout)   Timeout in seconds (default = ",DEFAULT_TIMEOUT,")\n";
  print " -m (--mshost)    saprouter string to message server\n";
  print " -a (--ashost)    saprouter string to application server\n";
  print " -r (--r3name)    SAP SID\n";
  print " -s (--sysnr)     SAP System number\n";
  print " -n (--pingcnt)   Number of echo request to send (default=4)\n";
  print " -i (--pingint)   Number of seconds between interval (default=0)\n";
  print " -k (--pingkb)    Number of KB to send (default=0)\n";
  print " -w (--warn)      Warning value of average round trip time in ms\n";
  print " -c (--crit)      Critical value of average round trip time in ms\n";
  print " -h (--help)      Help\n";
  print " -V (--version)   Program version\n";
  print " -v (--verbose)   Print some useful information\n";
  print " -L (--license)   Print license information\n";
  print "\n";
}

sub print_gpl {
  print <<EOD;

  Copyright (C) 2007 by Herbert Stadler
  email: hestadler\@gmx.at

  License Information:
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 3 of the License, or
  (at your option) any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License 
  along with this program; if not, see <http://www.gnu.org/licenses/>. 

EOD

}

sub print_revision {
  my ($l_prog,$l_revision)=@_;

  print <<EOD

$l_prog $l_revision, Copyright (C) 2007 Herbert Stadler

This program comes with ABSOLUTELY NO WARRANTY; 
for details type "$l_prog -L".
EOD
}


#__END__


=head1 NAME

check_sap_rfcping

=head1 DESCRIPTION

Check SAP Availability and Response Time (Packet Round Trip Time) via SAP load balancing or directly to a specific application server based on SAPs RFCSDK.

This plugin calls rfcping to connect to a SAP application or message server and returns some state info (eg: packet round trip time).

Plugin created for Nagios Monitoring.

=head1 SYNOPSIS

check_sap_rfcping [-h] [-L] [-t timeout] [-v] [-V] [-r r3name] [-s sysnr] [-n pingcount] [-i pinginterval] [-k pingKB] [-w warn] [-c crit] -m mshost | -a ashost

if the B<-w> and B<-c> options are missing the average round trip time will not be checked.

for more information call:

     check_sap_rfcping -h
     perldoc check_sap_rfcping


=head1 AUTHOR

 Herbert Stadler, Austria (hestadler@gmx.at)
 December 2007

 This plugin is a contribution to the nagios community.

=head1 REQUIRED SOFTWARE

 RFCSDK from SAP


=head1 HOW TO CHECK THE SAP RFC FUNCTIONALITY

Please check the functionality with the user under which the nagios service is running (normally nagios: su - nagios)

Don't check with root, because of global permissions.

Examples of native rfcping commands:

=over 2

=item Checking a SPECIFIC APPLICATION SERVER

rfcping ashost=/H/sapgate1/S/3297/H/pcintel sysnr=53

=item Checking servers via LOAD BALANCING

rfcping r3name=BIN mshost=/H/sapgate1/S/3297/H/hs0311 group=PUBLIC

=back

 rfcping is a command from the SAP RFCSDK toolkit 
 (http://service.sap.com/swdc).

Information about where to find the current version of the RFC Library is described in SAP Note 413708. SAP Note 27517 describes the installation of the RFCSDK.

SAP is a trademark of SAP AG, Germany.

=head1 ADAPTION OF SCRIPT

Before calling the script please check some variables which defines the path to rfcping and libraries.

 use constant RFCPING => "/usr/local/rfcsdk/bin/rfcping";

Please modify the environment variable LD_LIBRARY_PATH if you havn't defined the rfcsdk libraries globally via /etc/ld.so.conf (ldconfig).

 $ENV{'LD_LIBRARY_PATH'} = '/usr/local/rfcsdk/lib/'; 

=head1 CONFIGURATION IN NAGIOS

 Copy this plugin to the nagios plugin installation directory 
 e.g.: /usr/lib(64)/nagios/plugin

 COMMAND DEFINITION:

 # "check_sap_rfcping" command definition
 # checking via Message Server
 define command{
   command_name check_sap_rfcping_ms
   command_line $USER1$/check_sap_rfcping -m /H/$HOSTADDRESS$ -r $ARG1$
 }

 # checking a specific application server
 define command{
   command_name check_sap_rfcping_as
   command_line $USER1$/check_sap_rfcping -a /H/$HOSTADDRESS$ -s $ARG1$
 }


=head1 PLUGIN HISTORY

 Version 1.3 - 2009-12-04       LD_LIBRARY_PATH added if not globally defined
 Version 1.2 - 2009-02-17       some new "use lib .." statements
 Version 1.1 - 2007-12-19       fixed problem with **ePN
                                (Missing right curly or square ...)
 Version 1.0 - 2007-12-16	first release

=head1 COPYRIGHT AND DISCLAIMER

 Copyright (C) 2007 by Herbert Stadler
 email: hestadler@gmx.at

 License Information:
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License 
 along with this program; if not, see <http://www.gnu.org/licenses/>. 
 

=cut
