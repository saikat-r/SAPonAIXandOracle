<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">  
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />  
 
<title>User Management System (Tom Cameron for NetTuts)</title>
<link rel="stylesheet" href="loginpagestyle.css" type="text/css" />
</head>  
<body>  
<div id="main">

<?php
if(!empty($_SESSION['LoggedIn']) && !empty($_SESSION['UserID']))
{
     ?>
 
     <h1>Member Area</h1>
     <pThanks for logging in! You are <code><?=$_SESSION['UserID']?></code> and your email address is <code><?=$_SESSION['EMAIL']?></code>.</p>
      
     <?php
}
elseif(!empty($_POST['username']) && !empty($_POST['password']))
{
    $username = mysql_real_escape_string($_POST['username']);
    $password = md5(mysql_real_escape_string($_POST['password']));
     
    $checklogin = mysql_query("SELECT * FROM users WHERE UserID = '".$username."' AND Password = '".$password."'");
     
    if(mysql_num_rows($checklogin) == 1)
    {
        $row = mysql_fetch_array($checklogin);
        $email = $row['EMAIL'];
         
        $_SESSION['UserID'] = $username;
        $_SESSION['EMAIL'] = $email;
        $_SESSION['LoggedIn'] = 1;
         
        echo "<h1>Success</h1>";
        echo "<p>We are now redirecting you to the member area.</p>";
        echo "<meta http-equiv='refresh' content='=2;MAIN.php' />";
    }
    else
    {
        echo "<h1>Error</h1>";
        echo "<p>Sorry, your account could not be found. Please <a href=\"MAIN.php\">click here to try again</a>.</p>";
    }
}
else
{
    ?>
     
   <h1>GSPO Basis Member Login</h1>
     
   <p>Thanks for visiting! Please either login below, or <a href="register.php">click here to register</a>.</p>
     
    <form method="post" action="MAIN.php" name="loginform" id="loginform">
    <fieldset>
        <label for="username">UserID:</label><input type="text" name="username" id="username" /><br />
        <label for="password">Password:</label><input type="password" name="password" id="password" /><br />
        <input type="submit" name="login" id="login" value="Login" />
    </fieldset>
    </form>
     
   <?php
}
?>
 
</div>
</body>
</html>