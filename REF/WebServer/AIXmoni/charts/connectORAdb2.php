<html>
<head>
<title>TEST PHP ORA DB</title>
</head>
<body>
<p align=center>Here you will see if AGH DB is connected or NOT ... !</p>


<?php
    /*
	First TRY
	*/
	$db = "(DESCRIPTION=(ADDRESS_LIST = (ADDRESS = (PROTOCOL = TCP)(HOST = 192.168.1.34)(PORT = 1521)))(CONNECT_DATA=(SID=orcl)))" ;
	$db = "(DESCRIPTION=(ADDRESS = (COMMUNITY = SAP.WORLD)(PROTOCOL = TCP)(HOST = lindbagh5800c4.edc.linde.grp)(PORT = 1558))(CONNECT_DATA = (SERVER = DEDICATED)(SERVICE_NAME = AGH)))" ;

    if($c = OCILogon("system", "Linde1234", $db))
    {
        echo 'Successfully connected to Oracle' ;
        OCILogoff($c);
    }
    else
    {
        $err = OCIError();
        echo 'Connection failed.' . $err[text];
    }

	
	/*
	Second Try
	$db = "(DESCRIPTION=(ADDRESS = (COMMUNITY = SAP.WORLD)(PROTOCOL = TCP)(HOST = lindbagh5800c4.edc.linde.grp)(PORT = 1558))(CONNECT_DATA = (SERVER = DEDICATED)(SERVICE_NAME = AGH)))" ;
	$connect = oci_connect("system", "Linde1234", $db);
    $query = "SELECT * from dba_users";
    $result = oci_parse($connect, $query);
    oci_execute($result);
    $tmpcount = oci_fetch($result);
    if ($tmpcount==1) {
        echo 'Login Success';}
    else
    {
        echo 'Login Failed';
    }
	*/	
	
	/*
	Third Try
	$db = "(DESCRIPTION=(ADDRESS = (COMMUNITY = SAP.WORLD)(PROTOCOL = TCP)(HOST = lindbagh5800c4.edc.linde.grp)(PORT = 1558))(CONNECT_DATA = (SERVER = DEDICATED)(SERVICE_NAME = AGH)))" ;
	if ($c=OCILogon('system', 'Linde1234', $db)) {
		echo 'Successfully connected to AGH Oracle DB.';
		OCILogoff($c);
		} 
	else {
		$err = OCIError();
		echo 'Connection failed.' . $err[text];
	}
	*/
?>
</body>
</html>

