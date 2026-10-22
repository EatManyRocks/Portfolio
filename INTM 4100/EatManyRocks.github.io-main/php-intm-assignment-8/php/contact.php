<?php
$servername = "localhost";
$username = "root";
$password = "";

try {
  $conn = new PDO("mysql:host=$servername;dbname=contact_form_db", $username, $password);
  $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
  exit("Connection failed: " . $e->getMessage());
}

if (empty($_POST["username"]) || empty($_POST["useremail"]) || empty($_POST["usermessage"])) {
  exit("Not all fields filled in");
}

if (!filter_var($_POST["useremail"], FILTER_VALIDATE_EMAIL)) {
  exit("Invalid email");
}

$name = htmlspecialchars($_POST["username"]);
$email = htmlspecialchars($_POST["useremail"]);
$message = htmlspecialchars($_POST["usermessage"]);

$stmt = $conn->prepare("INSERT INTO messages (name, email, message) VALUES (?, ?, ?)");
$stmt->execute([$name, $email, $message]);

$conn = null;

header("Location: view_message.php");
exit();
