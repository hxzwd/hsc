#!/bin/bash

echo TEST PARALLEL 1
time ./test.sh

echo TEST NON PARALLEL
time ./test.sh 1

echo TEST PARALLEL 2
time ./test.sh 2

echo TEST PARALLEL 3
time ./test.sh 3

