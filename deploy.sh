#!/bin/bash

# Manually setting the time in the source code of parameter 1
# either ./deploy.sh
#	la_jument
# 	simpnasklubb
cd arduino/$1

DATE=$(date +%s)
sed -i 0,/unsigned\ long\ time\ =.*/s//unsigned\ long\ time\ =\ $DATE\;/ $1.ino
make upload

# Reversing changes made in source file
sed -i 0,/unsigned\ long\ time\ =.*/s//unsigned\ long\ time\ =\ 0\;/ $1.ino
