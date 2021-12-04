 <head>
  <meta charset="UTF-8">
</head>
<h1> Lighthouses </h1>
 <?php
  $files = glob("*.php");

  for ($i = 0; $i < count($files); $i++) {
    if ($files[$i] != "index.php") {
      include $files[$i];
    }
  }
	echo "<br> Time: " . date("H:i:s") . "<br>";
?>
