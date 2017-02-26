#!/usr/bin/perl
# Sumit Das 2015 06 10
use warnings;
use strict;

my $mode = "debug";
print "Enter debug mode!\n debug / nodebug\n";
print "[for default mode nodebug] - Press enter !   ";
my $guess = <STDIN>;
chomp($guess);
if ($mode eq $guess) {
        print "debug mode!\n";
}else{
        print "nodebug mode!\n";
	$mode = "nodebug";
}

open(FH, '>', 'moniLISTtoday') or die "cannot open file";
select FH;

my %MONI=(
        	Abhijit 	=> 	[ 'PRD', 'P8B', ],  
		Ali 		=> 	[ 'NULL', ], 	
		Alok 		=> 	[ 'GPR', 'P2E', ],  
		Ashok 		=> 	[ 'NULL', ],  
		Avik 		=> 	[ 'GPA', 'GPE', 'GPB', ],
		Christer	=> 	[ 'NULL', ],  	
		Deepjyoti	=> 	[ 'P6E', 'P1B', ],	
		Gaurav 		=> 	[ 'PGH', 'GPC', ],
		Kishore 	=> 	[ 'NULL', ], 
		Saikat 		=> 	[ 'ZP2', 'P9E', 'CRP', ],
		Sanjay 		=> 	[ 'NULL', ],
		Santanu 	=> 	[ 'VP1', 'VP4', 'P9B', ],
		Santosh 	=> 	[ 'PGX', 'LPR', ], 
		Seshagiri	=> 	[ 'NULL', ],  	
		Simon 		=> 	[ 'NULL', ],  
		Subhasis	=> 	[ 'BWP', 'PCB', ],
		Sudipta		=> 	[ 'P01', 'PNU', ],
		Sumit 		=> 	[ 'GPF', 'P7E', ],
		Tushar 		=> 	[ 'P8E', 'GPL', 'PXI', ],
);

foreach my $group (keys %MONI) {
    print "$group will today monitor	\n";
    foreach (@{$MONI{$group}}) {
        print "\t$_\n";
    }
}

close FH;

#system("sh", "sendmailAIX3.sh", "sam8boc@gmail.com", "moniLISTtoday", "Perl_on_AIX")
my $file = "moniLISTtoday";
my $message = do {
    local $/ = undef;
    open my $fh, "<", $file
        or die "could not open $file: $!";
    <$fh>;
};
my $to = 'si_basis@linde.com';
my $from = 'AIX-Monitoring';
my $subject = 'SI Basis SAP Monitoring List for Today';
open(MAIL, "|/usr/sbin/sendmail -t");
# Email Header
print MAIL "To: $to\n";
print MAIL "From: $from\n";
print MAIL "Subject: $subject\n\n";
# Email Body
print MAIL $message;
close(MAIL);

print "Email Sent to SI  Successfully\n";

open(FH1, '>', 'moniAUTOperlLOG') or die "cannot open file";
select FH1;

#system("rm moniAUTOperlLOG2");
#system("ls -tr");
print "Main Perl script started...";
foreach my $group (keys %MONI) {
    print "$group Log File	\n";
    foreach (@{$MONI{$group}}) {
        print "\t$_\n";
	system("sh /home/users/in10c2/sumit/moniscripts/moni-server-v.3.5.sh $_ $group $mode")
#       system("more /home/users/in10c2/sumit/ALL-LPAR-List | grep $_ >> moniAUTOperlLOG2 ");
    }
}


close FH1;
