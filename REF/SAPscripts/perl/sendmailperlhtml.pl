#!/usr/bin/perl
 
$to = 'sam8boc@gmail.com';
$from = 'ORACLE';
$subject = 'Test Email Part 2';
$message = '<h1>This is test email sent by Perl Script</h1>';
 
open(MAIL, "|/usr/sbin/sendmail -t");
 
# Email Header
print MAIL "To: $to\n";
print MAIL "From: $from\n";
print MAIL "Subject: $subject\n\n";
print MAIL "Content-type: text/html\n";
# Email Body
print MAIL $message;

close(MAIL);
print "Email Sent Successfully\n";