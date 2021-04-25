#!/bin/sh

cd "$(dirname "$(readlink -f "$0")")"
TPP="./../bin/tpp"
if [[ -f "${TPP}.exe" ]]; then TPP="${TPP}.exe"; fi
TPP="$TPP -P -fno-spc -fno-lf -Werror"

for file in *.h; do
	echo "Running: $file"
	$TPP $file || {
		error="$?"
		echo "Command failed: '$TPP $file' -> '$error'"
		exit $error
	}
done
