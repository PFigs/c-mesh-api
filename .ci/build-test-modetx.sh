#!/usr/bin/env bash
# Wirepas Oy
cd test || exit 1
make test_mode=1 txnode=1 clean
make test_mode=1 txnode=1
