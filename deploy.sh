#!/bin/bash

# Manually setting the time in the source code of parameter 1
# either deploy:
#	la_jument
# 	simpnasklubb
DATE=$(date +%s)
sed -i 0,/unsigned\ long\ time\ =.*/s//unsigned\ long\ time\ =\ $DATE\;/ arduino/$1/$1.ino
cd arduino/$1
make upload
