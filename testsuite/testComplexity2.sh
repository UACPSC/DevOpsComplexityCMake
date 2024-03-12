#!/bin/bash

srcml --text="void f(){ if (a < b); }" -l C++ | ./srccomplexity | grep -Fx "1" > /dev/null
