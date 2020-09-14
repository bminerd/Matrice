#!/bin/bash

set -e

pushd . > /dev/null

# Switch current/working directory to here
cd "${0%/*}"

cd Build
ctest .. --verbose

popd > /dev/null
