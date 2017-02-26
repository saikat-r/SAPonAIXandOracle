#!/usr/bin/perl
use MIME::Lite;
 
$to = 'sam8boc@gmail.com';
$cc = 'sam8ibm@mail.com';
$from = 'ORACLE';
$subject = 'Test EmailPart 3';
$message = 'This is test email sent by Perl Script with attachement on AIX';

$msg = MIME::Lite->new(
                 From     => $from,
                 To       => $to,
                 Cc       => $cc,
                 Subject  => $subject,
                 Type     => 'multipart/mixed'
                 );
                 
# Add your text message.
$msg->attach(Type         => 'text',
             Data         => $message
            );
            
# Specify your file as attachement.
$msg->attach(Type        => 'html',
             Path        => '/oracle/DGE/SQLmoni_Tablespace_Usage_Percent_Info.html',
             Filename    => 'SQLmoni_Tablespace_Usage_Percent_Info.html',
             Disposition => 'attachment'
            );       
$msg->send;
print "Email Sent Successfully\n";
