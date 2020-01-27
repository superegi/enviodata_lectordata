#!/bin/bash


echo 'CSubiendo el archivo test2.ino al sistema, ojalá esté....'
lsusb

sudo arduino --upload test2.ino --port /dev/ttyUSB0


echo 'Leyendo el serial'
sudo stty -F /dev/ttyUSB0 115200 raw -clocal -echo
sudo cat /dev/ttyUSB0
