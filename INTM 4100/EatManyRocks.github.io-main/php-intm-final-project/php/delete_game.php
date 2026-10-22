<?php
require "dbopen.php";

$id = $_GET["id"];

if (!$id) {
  exit("No ID provided");
}

$stmt = $conn->prepare("DELETE FROM games WHERE id = ?");
$stmt->execute([$id]);

require "dbclose.php";
header("Location: view_games.php");
exit();
