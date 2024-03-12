#!/bin/bash

srcml --text="void f(){ if (a < b); }" -l C++ | ./srccomplexity | grep -Fx "2" > /dev/null
