<html>
<head>
<title>TEST PHP ORA DB</title>
</head>
<body>
<p align=center>Here you will see if AGH DB is connected or NOT ... !</p>


<?php
    /*
	First TRY
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
	*/
	
	/*
	Second Try
	*/
	$db = "(DESCRIPTION=(ADDRESS = (COMMUNITY = SAP.WORLD)(PROTOCOL = TCP)(HOST = lindbagh5800c4.edc.linde.grp)(PORT = 1558))(CONNECT_DATA = (SERVER = DEDICATED)(SERVICE_NAME = AGH)))" ;
	$connect = oci_connect("system", "Linde1234", $db);
    $query = "select t.tablespace, t.totalspace as ' Totalspace(MB)', round((t.totalspace-fs.freespace),2)
as 'Used Space(MB)', fs.freespace as 'Freespace(MB)', round(((t.totalspace-fs.freespace)/t.totalspace)
*100,2) as '% Used', round((fs.freespace/t.totalspace)*100,2) as '% Free' from (select round(sum(d.bytes)/(1024*1024))
as totalspace, d.tablespace_name tablespace from dba_data_files d group by d.tablespace_name) t,
(select round(sum(f.bytes)/(1024*1024)) as freespace, f.tablespace_name tablespace from
dba_free_space f group by f.tablespace_name) fs where t.tablespace=fs.tablespace order by t.totalspace desc;
";
    $result = oci_parse($connect, $query);
    oci_execute($result);
    $tmpcount = oci_fetch($result);
    if ($tmpcount==1) {
        echo 'Login Success';}
    else
    {
        echo 'Login Failed';
    }
	
	
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

