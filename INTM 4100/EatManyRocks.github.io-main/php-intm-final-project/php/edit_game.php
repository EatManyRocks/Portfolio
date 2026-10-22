<?php
require "dbopen.php";

$id = $_GET['id'];

if (!$id) {
  exit("No ID provided");
}

$stmt = $conn->prepare("SELECT * FROM games WHERE id = ?");
$stmt->execute([$id]);
$game = $stmt->fetch(PDO::FETCH_ASSOC);

if (!$game) {
  exit("No game found");
}

require "dbclose.php";
?>

<!doctype html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <title>Edit game</title>
  <link rel="stylesheet" href="/css/main.css">
</head>

<body>
  <h2>
    <a href="../index.html">Return to Main Menu</a>
  </h2>
  <hr>
  <br>
  <form action="edit_game-submit.php" method="post">
    <input type="hidden" name="gameid" value="<?php echo $id ?>">

    <p>
      <label for="title">Title:</label>
      <input type="text" id="title" name="gametitle" value="<?php echo $game['title'] ?>" maxlength="100">
    </p>
    <p>
      <label for="developer">Developer:</label>
      <input type="text" id="developer" name="gamedeveloper" value="<?php echo $game['developer'] ?>" maxlength="50">
    </p>
    <p>
      <label for="hours">Hours Played:</label>
      <input type="number" step="0.1" min="0" max="9999999" id="hours" name="gamehours" value="<?php echo $game['hours'] ?>">
    </p>
    <p>
      <label for="review">Review:</label>
      <textarea id="review" name="gamereview" rows="4" cols="50"><?php echo $game['review'] ?></textarea>
    </p>
    <p>
      <input type="submit" value="submit">
    </p>
  </form>
</body>

</html>
