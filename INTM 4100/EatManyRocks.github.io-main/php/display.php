<?php
$userDataFile = fopen("data.csv", "r");

while (!feof($userDataFile)) { // loop until end of file is reached

  echo "<tr>";

  $line = fgetcsv($userDataFile); // parse each line and save it in $line variable as an array 

  foreach ($line as $x) {

    echo "<td>" . $x . "</td>";
  }

  echo "</tr>";
}

echo "</table>";

fclose($userDataFile);
