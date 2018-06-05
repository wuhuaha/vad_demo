#!/usr/bin/env bash
FILE=./vad_demo
valgrind --leak-check=full --show-leak-kinds=all --show-reachable=no --track-origins=yes $FILE
