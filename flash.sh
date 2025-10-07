#!/bin/bash

[[ $#  -eq 0 ]] && echo "usage $0 <filename>" && exit 1

sudo ./mdloader --first --restart --download $1
