#!/bin/bash


gcc main.c -lpthread -o main_bin
gcc main_1.c -o main_bin_1
gcc main_2.c -lpthread -o main_bin_2
gcc main_3.c -lpthread -o main_bin_3

