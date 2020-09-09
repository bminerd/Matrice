#!/bin/bash

pushd .

# Switch current/working directory to here
cd "${0%/*}"

if [ ! -d "Dependencies" ]; then
    mkdir Dependencies
fi

cd Dependencies

if [ ! -d "Plat4m_Core" ]; then
    git clone https://github.com/bminerd/Plat4m_Core.git
fi

if [ ! -d "Eigen" ]; then
    git clone https://gitlab.com/libeigen/eigen.git Eigen
fi

popd
