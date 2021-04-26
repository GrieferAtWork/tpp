#!/bin/sh

cd "$(dirname "$(readlink -f "$0")")"
TPP="./../bin/tpp"
if [[ -f "${TPP}.exe" ]]; then TPP="${TPP}.exe"; fi
TPP="$TPP -P -Werror"

for file in *.h; do
	echo "Running: $TPP -fno-spc -fno-lf $file"
	$TPP -fno-spc -fno-lf $file || {
		error="$?"
		echo "Command failed: '$TPP -fno-spc -fno-lf $file' -> '$error'"
		exit $error
	}
	echo "Running: $TPP $file"
	$TPP $file > /dev/null || {
		error="$?"
		echo "Command failed: '$TPP $file' -> '$error'"
		exit $error
	}
done
