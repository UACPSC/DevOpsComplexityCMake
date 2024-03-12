#!/bin/bash

srcml --text="void f(){}" -l C++ | ./srccomplexity | grep -Fx "1" > /dev/null

