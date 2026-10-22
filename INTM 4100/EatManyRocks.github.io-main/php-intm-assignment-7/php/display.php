<?php
$userDataFile = fopen("data.csv", "r");

echo "<table border='1'>";
echo "<tr>";
echo "<th>Name</th>";
echo "<th>Phone</th>";
echo "<th>Email</th>";
echo "</tr>";

while (($line = fgetcsv($userDataFile)) !== false) {
  echo "<tr>";
  foreach ($line as $x) {
    echo "<td>" . $x . "</td>";
  }

  echo "</tr>";
}

echo "</table>";
fclose($userDataFile);
