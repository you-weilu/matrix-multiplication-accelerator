#!/bin/tcsh

rm -rf xcelium.d xrun.log xrun.history waves.shm

source /vol/ece303/genus_tutorial/cadence.env

xrun \
    -64bit \
    -sv \
    -access +rw \
    -timescale 1ns/1ps \
    ../../rtl/src/systolic_data_setup.sv \
    -top systolic_data_setup \
    -gui
