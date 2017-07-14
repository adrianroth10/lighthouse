#!/bin/bash
julia estimate.jl la_jument
julia estimate.jl simpnasklubb

LA_JUMENT=($(cat la_jument_out))
sed -i 0,/a1\ =.*/s//a1\ =\ ${LA_JUMENT[0]}\;/ ../arduino/la_jument/la_jument.ino
sed -i 0,/b1\ =.*/s//b1\ =\ ${LA_JUMENT[1]}\;/ ../arduino/la_jument/la_jument.ino
sed -i 0,/c1\ =.*/s//c1\ =\ ${LA_JUMENT[2]}\;/ ../arduino/la_jument/la_jument.ino
sed -i 0,/a2\ =.*/s//a2\ =\ ${LA_JUMENT[3]}\;/ ../arduino/la_jument/la_jument.ino
sed -i 0,/b2\ =.*/s//b2\ =\ ${LA_JUMENT[4]}\;/ ../arduino/la_jument/la_jument.ino
sed -i 0,/c2\ =.*/s//c2\ =\ ${LA_JUMENT[5]}\;/ ../arduino/la_jument/la_jument.ino

SIMPNASKLUBB=($(cat simpnasklubb_out))
sed -i 0,/a1\ =.*/s//a1\ =\ ${SIMPNASKLUBB[0]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/b1\ =.*/s//b1\ =\ ${SIMPNASKLUBB[1]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/c1\ =.*/s//c1\ =\ ${SIMPNASKLUBB[2]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/a2\ =.*/s//a2\ =\ ${SIMPNASKLUBB[3]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/b2\ =.*/s//b2\ =\ ${SIMPNASKLUBB[4]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
sed -i 0,/c2\ =.*/s//c2\ =\ ${SIMPNASKLUBB[5]}\;/ ../arduino/simpnasklubb/simpnasklubb.ino
