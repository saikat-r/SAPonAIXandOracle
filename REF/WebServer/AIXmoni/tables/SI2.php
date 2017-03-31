<html>
	<head>
		<title>SI BASIS GENESIS</title>
		<meta http-equiv="content-type" content="text/html; charset=utf-8" />
		<meta name="description" content="" />
		<meta name="keywords" content="" />
		<!--5grid--><!--script src="css/5grid/viewport.js"></script><!--[if lt IE 9]><script src="css/5grid/ie.js"></script><![endif]--><!--link rel="stylesheet" href="css/5grid/core.css" />
		<!-- link rel="stylesheet" href="css/style.css" />
		<!--[if IE 9]><link rel="stylesheet" href="css/style-ie9.css" /><![endif]-->
	</head>

<style type="text/css">
h1 {
    color: blue;
    text-align: left;
    font-family: verdana,sans-serif;
        font-size:20px;
}
h2 {
    color: orange;
    text-align: left;
    font-family: verdana,sans-serif;
        font-size:15px;
}
h3 {
    color: green;
    text-align: left;
    font-family: verdana,sans-serif;
        font-size:10px;
}

table {
        font-family: verdana,arial,sans-serif;
        font-size:11px;
        color:#333333;
        border-width: 1px;
        border-color: #999999;
        border-collapse: collapse;
}
th {
        background:#b5cfd2 url('cell-blue.jpg');
        border-width: 1px;
        padding: 8px;
        border-style: solid;
        border-color: #999999;
}
td {
        background:#dcddc0 url('cell-grey.jpg');
        border-width: 1px;
        padding: 8px;
        border-style: solid;
        border-color: #999999;
}
</style>



<?php
//Step1
 $db = mysqli_connect('localhost','rusty','Iamroot0','test')
 or die('Error connecting to MySQL server.');
?>

 <body>
 <h1>GSPO Basis Team</h1>
 <tr><th>First Name</th><th>Last Name</th><th>EMAIL</th><th>Group</th></tr>

<?php
//Step2
$query = "SELECT * FROM sibasismembers order by FirstName";
mysqli_query($db, $query) or die('Error querying database.');

//Step3
$result = mysqli_query($db, $query);
$row = mysqli_fetch_array($result);

echo "<table>";
while ($row = mysqli_fetch_array($result)) {
 $FName = $row['FirstName'];
 $LName = $row['LastName'];
 $Email = $row['EMAIL'];
 $Team = $row['TEAM'];
 echo "<tr><td>".$FName."</td><td>".$LName."</td><td>".$Email."</td><td>".$Team."</td></tr>";
 // echo $row['FirstName'] . ' ' . $row['LastName'] . ': ' . $row['EMAIL'] . ' ' . $row['TEAM'] .'<br />';
}
//Step 4
mysqli_close($db);
?>

</body>
</html>