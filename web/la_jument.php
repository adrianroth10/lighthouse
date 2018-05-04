<h3> La Jument (France) </h3>
 <?php
	$a0 = 32311.827255221066;
	$a1 = -109.74735122541995;
	$a2 = .3159008870699148;
	$b0 = 59092.08075177983;
	$b1 = 219.76836259192618;
	$b2 = -.6533837940808918;

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
