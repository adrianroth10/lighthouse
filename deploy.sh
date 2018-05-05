#!/bin/bash
set -e

# Manually setting the time in the source code of parameter 1
# either ./deploy.sh
#	la_jument
# 	simpnasklubb
#	web (or launch the web page

if [ "$1" = "web" ]; then
	function error_trap {
		printf "Error occured!\n"
		printf "Cleaning\n"
		sudo umount mount
		rm -r mount
	}
	trap 'error_trap' ERR

	printf "FTP password: "
	read -s PASSWORD
	printf "\r"

	printf "Mounting FTP\n"
	mkdir -p mount
	sudo curlftpfs -o allow_other ftp://rikardroth:$PASSWORD@ws64.surftown.com/adrianroth.se/lighthouse mount

	printf "Deploying files\n"
	rm -r mount/*
	cp -r -v web/*.php mount

	printf "Cleaning\n"
	sudo umount mount
	rm -r mount

	printf "Done\n"
else
	make -C arduino/setTime upload
	make -C arduino/$1 upload
fi
