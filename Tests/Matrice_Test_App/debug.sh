#!/bin/bash

set -e

pushd .

# Switch current/working directory to here
cd "${0%/*}"

cd Build

gdbserver --once --remote-debug localhost:2331 Matrice_Test_App

popd
