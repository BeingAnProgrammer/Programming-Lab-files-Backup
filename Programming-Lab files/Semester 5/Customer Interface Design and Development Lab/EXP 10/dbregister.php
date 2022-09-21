<!-- USING PHP: -->
<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "sample";
// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

$sql = "CREATE TABLE userinfo (
name VARCHAR(30) NOT NULL,
emailid VARCHAR(30) NOT NULL,
website VARCHAR(50),
comments varchar(200),
gender char(7) 
)";
if ($conn->query($sql) === TRUE) {
  echo "Table userinfo created successfully";
} else {
  echo "Error creating table: " . $conn->error;
}
//get the data from html file
$name=$_POST["name"];
$email=$_POST["email"];
$website=$_POST["website"];
$comments=$_POST["comments"];
$gender=$_POST["gender"];
//$sql = "INSERT INTO `tbl_contact` (`Id`, `fldName`, `fldEmail`, `fldPhone`, `fldMessage`) VALUES ('0', '$txtName', '$txtEmail', '$txtPhone', '$txtMessage');"
//insert data into database
$sql = "INSERT INTO userinfo (name, emailid, website,comments,gender)
VALUES ('$name', '$email', '$website','$comments','$gender')";
echo "inserted";
if ($conn->query($sql) === TRUE) {
  echo "New record created successfully";
} else {
  echo "Error: " . $sql . "<br>" . $conn->error;
}
$conn->close();
?>