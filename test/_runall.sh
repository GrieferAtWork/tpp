#!/bin/sh

cd "$(dirname "$(readlink -f "$0")")/.."
TPP="$(pwd)/bin/tpp"
if [[ -f "${TPP}.exe" ]]; then TPP="${TPP}.exe"; fi
TPP="$TPP -P -Werror"

# testFile <filename>
testFile() {
	echo "Running: $TPP -fno-spc -fno-lf $1"
	$TPP -fno-spc -fno-lf "$1" || {
		error="$?"
		echo "Command failed: '$TPP -fno-spc -fno-lf $1' -> '$error'"
		exit $error
	}
	echo "Running: $TPP $1"
	$TPP "$1" > /dev/null || {
		error="$?"
		echo "Command failed: '$TPP $1' -> '$error'"
		exit $error
	}
}

cd "test"
for file in *.h; do
	testFile "$file"
done

# This test requires some special care as it relates to relative includes
cd inner
testFile "test.h"
cd ..
