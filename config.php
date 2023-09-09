<?php

$servername = "localhost";

$username = "root"; 

$password = ""; 
$dbname ="myDB";

$con = new mysqli($servername, $username, $password, $dbname);

if ($con->connect_error) {

    die("Connection failed: " . $con->connect_error);

}
/*$sql = "CREATE DATABASE myDB";
if ($conn->query($sql) === TRUE) {
  echo "Database created successfully";
} else {
  echo "Error creating database: " . $conn->error;
}*/

//$con->close();
?>

