#!/bin/bash
printf "Estimating parameters\n"
julia estimate.jl la_jument
julia estimate.jl simpnasklubb

printf "Deploying parameters\n"
LA_JUMENT=($(cat la_jument_out))
sed -i 0,/double\ a0\ =.*/s//double\ a0\ =\ ${LA_JUMENT[0]}\;/ ../arduino/la_jument/la_jument.ino
sed -i 0,/double\ a1\ =.*/s//double\ a1\ =\ ${LA_JUMENT[1]}\;/ ../arduino/la_jument/la_jument.ino
sed -i 0,/double\ a2\ =.*/s//double\ a2\ =\ ${LA_JUMENT[2]}\;/ ../arduino/la_jument/la_jument.ino
sed -i 0,/double\ b0\ =.*/s//double\ b0\ =\ ${LA_JUMENT[3]}\;/ ../arduino/la_jument/la_jument.ino
sed -i 0,/double\ b1\ =.*/s//double\ b1\ =\ ${LA_JUMENT[4]}\;/ ../arduino/la_jument/la_jument.ino
sed -i 0,/double\ b2\ =.*/s//double\ b2\ =\ ${LA_JUMENT[5]}\;/ ../arduino/la_jument/la_jument.ino

sed -i 0,/\$a0\ =.*/s//\$a0\ =\ ${LA_JUMENT[0]}\;/ ../web/la_jument.php
sed -i 0,/\$a1\ =.*/s//\$a1\ =\ ${LA_JUMENT[1]}\;/ ../web/la_jument.php
sed -i 0,/\$a2\ =.*/s//\$a2\ =\ ${LA_JUMENT[2]}\;/ ../web/la_jument.php
sed -i 0,/\$b0\ =.*/s//\$b0\ =\ ${LA_JUMENT[3]}\;/ ../web/la_jument.php
sed -i 0,/\$b1\ =.*/s//\$b1\ =\ ${LA_JUMENT[4]}\;/ ../web/la_jument.php
sed -i 0,/\$b2\ =.*/s//\$b2\ =\ ${LA_JUMENT[5]}\;/ ../web/la_jument.php

SIMPNASKLUBB=($(cat simpnasklubb_out))
sed -i 0,/double\ a0\ =.*/s//double\ a0\ =\ ${SIMPNASKLUBB[0]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/double\ a1\ =.*/s//double\ a1\ =\ ${SIMPNASKLUBB[1]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/double\ a2\ =.*/s//double\ a2\ =\ ${SIMPNASKLUBB[2]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/double\ b0\ =.*/s//double\ b0\ =\ ${SIMPNASKLUBB[3]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/double\ b1\ =.*/s//double\ b1\ =\ ${SIMPNASKLUBB[4]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/double\ b2\ =.*/s//double\ b2\ =\ ${SIMPNASKLUBB[5]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino

sed -i 0,/\$a0\ =.*/s//\$a0\ =\ ${SIMPNASKLUBB[0]}\;/ ../web/simpnasklubb.php
sed -i 0,/\$a1\ =.*/s//\$a1\ =\ ${SIMPNASKLUBB[1]}\;/ ../web/simpnasklubb.php
sed -i 0,/\$a2\ =.*/s//\$a2\ =\ ${SIMPNASKLUBB[2]}\;/ ../web/simpnasklubb.php
sed -i 0,/\$b0\ =.*/s//\$b0\ =\ ${SIMPNASKLUBB[3]}\;/ ../web/simpnasklubb.php
sed -i 0,/\$b1\ =.*/s//\$b1\ =\ ${SIMPNASKLUBB[4]}\;/ ../web/simpnasklubb.php
sed -i 0,/\$b2\ =.*/s//\$b2\ =\ ${SIMPNASKLUBB[5]}\;/ ../web/simpnasklubb.php
