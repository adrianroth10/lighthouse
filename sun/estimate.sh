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

SIMPNASKLUBB=($(cat simpnasklubb_out))
sed -i 0,/double\ a0\ =.*/s//double\ a0\ =\ ${SIMPNASKLUBB[0]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/double\ a1\ =.*/s//double\ a1\ =\ ${SIMPNASKLUBB[1]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/double\ a2\ =.*/s//double\ a2\ =\ ${SIMPNASKLUBB[2]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/double\ b0\ =.*/s//double\ b0\ =\ ${SIMPNASKLUBB[3]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/double\ b1\ =.*/s//double\ b1\ =\ ${SIMPNASKLUBB[4]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/double\ b2\ =.*/s//double\ b2\ =\ ${SIMPNASKLUBB[5]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
