<!doctype html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <title>Your Library</title>
  <link rel="stylesheet" href="/css/main.css">
</head>

<body>
  <h2>
    <a href="../index.html">Return to Main Menu</a>
  </h2>
  <hr>
  <br>
  <table border='1'>
    <tr>
      <th>#</th>
      <th>Title</th>
      <th>Developer</th>
      <th>Hours</th>
      <th>Review</th>
      <th>Date Created</th>
      <th>Last Edited</th>
    </tr>

    <?php
    require "dbopen.php";

    $stmt = $conn->query("SELECT * FROM games");
    while ($game = $stmt->fetch(PDO::FETCH_ASSOC)) {
      echo "<tr>";
      echo "<td>" . $game["id"] . "</td>";
      echo "<td>" . $game["title"] . "</td>";
      echo "<td>" . $game["developer"] . "</td>";
      echo "<td>" . $game["hours"] . "</td>";
      echo "<td>" . $game["review"] . "</td>";
      echo "<td>" . $game["created_at"] . "</td>";
      echo "<td>" . $game["edited_at"] . "</td>";
      echo "<td><a href='edit_game.php?id=" . $game["id"] . "'>Edit</a></td>";
      echo "<td><a href='delete_game.php?id=" . $game["id"] . "'>Delete</a></td>";
      echo "</tr>";
    }

    require "dbclose.php";
    ?>
  </table>

</body>

</html>
