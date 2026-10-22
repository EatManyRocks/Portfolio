<?php
require "dbopen.php";

if (empty($_POST["usertitle"]) || empty($_POST["userdeveloper"]) || empty($_POST["userhours"])) {
  exit("Not all fields filled in");
}

$title = htmlspecialchars($_POST["usertitle"]);
$developer = htmlspecialchars($_POST["userdeveloper"]);
$hours = htmlspecialchars($_POST["userhours"]);
$review = htmlspecialchars($_POST["userreview"]);

$stmt = $conn->prepare("INSERT INTO games (title, developer, hours, review) VALUES (?, ?, ?, ?)");
$stmt->execute([$title, $developer, $hours, $review]);

require "dbclose.php";
header("Location: view_games.php");
exit();
