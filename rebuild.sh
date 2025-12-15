#!/usr/bin/env bash

# Rebuild dwm.
set -e

yes | rm config.h patches.h
sudo make install
