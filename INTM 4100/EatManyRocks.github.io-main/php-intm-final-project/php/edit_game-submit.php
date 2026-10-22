<?php
require "dbopen.php";

if (empty($_POST["gametitle"]) || empty($_POST["gamedeveloper"]) || empty($_POST["gamehours"])) {
  exit("Not all fields filled in");
}

$id = htmlspecialchars($_POST["gameid"]);
$title = htmlspecialchars($_POST["gametitle"]);
$developer = htmlspecialchars($_POST["gamedeveloper"]);
$hours = htmlspecialchars($_POST["gamehours"]);
$review = htmlspecialchars($_POST["gamereview"]);

$stmt = $conn->prepare("UPDATE games SET title = ?, developer = ?, hours = ?, review = ?, edited_at = NOW() WHERE id = ?");
$stmt->execute([$title, $developer, $hours, $review, $id]);

require "dbclose.php";
header("Location: view_games.php");
exit();
