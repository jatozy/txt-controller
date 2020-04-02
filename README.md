# Introduction
A Wrapper for the C implementation and precompiled library of the txt controller from Fischertechnik.

# Build the Software
The binaries for the Fischertechnik TXT-Controller can be compiled in the Docker container which will be build with the toplevel Dockerfile.
The docker-compose file on the toplevel will build the container and will mount the toplevel folder as /workspace inside the container.

This docker-compose file is the base for the configuration of Visual Studio Code and for Travis-CI.
