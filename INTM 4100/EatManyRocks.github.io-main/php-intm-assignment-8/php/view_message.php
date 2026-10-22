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

echo "<table border='1'>";
echo "<tr>";
echo "<th>ID</th>";
echo "<th>Name</th>";
echo "<th>Email</th>";
echo "<th>Message</th>";
echo "<th>Created_At</th>";
echo "</tr>";

$stmt = $conn->query("SELECT * FROM messages");
while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
  echo "<tr>";
  foreach ($row as $x) {
    echo "<td>" . $x . "</td>";
  }

  echo "</tr>";
}
