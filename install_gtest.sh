#!/bin/bash

# Set Google Test version
GTEST_VERSION="release-1.11.0"

# Set installation path
INSTALL_DIR="${PWD}/usr"

# Marker file path
MARKER_FILE="${INSTALL_DIR}/.installed_gtest"

# Check if already installed
if [ -f "${MARKER_FILE}" ]; then
    echo "Google Test has already been installed. Skipping the compilation process."
else
    # Check if already downloaded
    if [ -d "googletest" ]; then
        echo "The 'googletest' directory already exists. Skipping the download process."
    else
        # Clone the Google Test repository
        git clone --branch ${GTEST_VERSION} --depth 1 https://github.com/google/googletest.git
    fi

    # Enter the 'googletest' directory
    cd googletest

    # Create the 'build' directory
    mkdir -p build && cd build

    # Build and install using CMake
    cmake -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} ..
    make
    make install

    # Create a marker file in the target directory
    touch "${MARKER_FILE}"

    # Return to the original directory
    cd ../..

    # Remove the downloaded source code
    rm -rf googletest
fi

# Continue with the rest of the script
echo "start ..."
