<h3> Falsterbo </h3>
 <?php
	$a0 = 32313.729583;
	$a1 = -158.733227;
	$a2 = 0.460269;
	$b0 = 53972.20695;
	$b1 = 269.366564;
	$b2 = -0.798887;

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
