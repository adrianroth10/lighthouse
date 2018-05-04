#!/bin/bash

# Manually setting the time in the source code of parameter 1
# either ./deploy.sh
#	la_jument
# 	simpnasklubb

cd arduino/setTime
make upload

cd arduino/$1
make upload

