<?php
$userDataFile = fopen("data.csv", "w");
$user = [];
$user[] = $_POST["username"];
$user[] = $_POST["userphone"];
$user[] = $_POST["useremail"];
fputcsv($userDataFile, $user);
fclose($userDataFile);
include "php/display.php";
