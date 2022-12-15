#!/bin/bash

{ cat input; } | $1 > output-expected
{ cat input; } | $2 > output-result

if [ diff -q file01 file02 ] then
    echo Files different
else
    echo Files same
fi