# Author: Ondřej Honus
# Github: https://github.com/ondrejhonus/gituploader

cmake_minimum_required(VERSION 3.5.0)

# Project name and version
project(gitup_project VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the executable
add_executable(gitup gitup.c)

# Specify the install path for the executable
install(TARGETS gitup DESTINATION bin)
