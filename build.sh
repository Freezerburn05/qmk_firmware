#!/bin/bash

./util/docker_cmd.sh qmk clean
./util/docker_build.sh massdrop/ctrl:Freezerburn05:build
