#!/bin/bash

cc -o testexe input-validation-check.c input.c libft.a -I ../../lib/include

./testexe

rm -f testexe