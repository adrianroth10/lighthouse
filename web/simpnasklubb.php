<h3> Simpnäsklubb (Sweden) </h3>
 <?php
	$a0 = 33073.590402;
	$a1 = -200.048746;
	$a2 = 0.581281;
	$b0 = 50712.115999;
	$b1 = 310.657722;
	$b2 = -0.920175;

 	$M = date("m");
 	$D = date("d");
 	$h = date("H");
 	$m = date("i");
 	$s = date("s");
	$d = (($M - 1) * 30 + $D);

	$sunrise = ($a0 + $a1 * $d + $a2 * $d * $d);
	$ssunrise = floor($sunrise / 3600) . ":" . floor(fmod($sunrise, 3600) / 60) . ":" . floor(fmod(fmod($sunrise, 3600), 60));
	$sunset = ($b0 + $b1 * $d + $b2 * $d * $d);
	$ssunset = floor($sunset / 3600) . ":" . floor(fmod($sunset, 3600) / 60) . ":" . floor(fmod(fmod($sunset, 3600), 60));
	$sec = $h * 3600 + $m * 60 + $s;

	echo "Sunrise: " . $ssunrise . "<br>";
	echo "Sunset: " . $ssunset . "<br>";
	echo "Status: ";
	if ($sec > $sunset or $sec < $sunrise) {
		echo "on";
	} else {
		echo "off";
	}
	echo "<br>";
?>
