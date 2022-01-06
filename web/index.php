 <head>
  <meta charset="UTF-8" title="Lighthouses">
  <title> Lighthouses on/off </title>
</head>
<h1> Lighthouses </h1>
 <?php
  $files = glob("*.php");

  $M = date("m");
  $D = date("d");
  $h = date("H");
  $m = date("i");
  $s = date("s");
  $d = (($M - 1) * 30 + $D);

  printf("<table><tr><td>Time:</td> <td>%s</td></tr></table>", date("H:i:s"));

  for ($i = 0; $i < count($files); $i++) {
    if ($files[$i] != "index.php") {
      include $files[$i];

      $sunrise = ($a0 + $a1 * $d + $a2 * $d * $d);
      $sunset = ($b0 + $b1 * $d + $b2 * $d * $d);
      $sec = $h * 3600 + $m * 60 + $s;
      
      printf("<table>");
      printf(
        "<tr><td>Sunrise:</td> <td>%02d:%02d:%02d</td></tr>",
        floor($sunrise / 3600),
        floor(fmod($sunrise, 3600) / 60),
        floor(fmod(fmod($sunrise, 3600), 60))
      );
      printf(
        "<tr><td>Sunset:</td> <td>%02d:%02d:%02d</td></tr>",
        floor($sunset / 3600),
        floor(fmod($sunset, 3600) / 60),
        floor(fmod(fmod($sunset, 3600), 60))
      );
      $status = ($sec > $sunset or $sec < $sunrise) ? "on" : "off";
      printf("<tr><td>Status:</td> <td>%s</td></tr>", $status);
      printf("</table>");
    }
  }
?>
