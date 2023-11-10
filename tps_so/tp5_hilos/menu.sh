#!/bin/bash
#
valor=""
until [ $valor == "q" ];do
	echo "[1]"
	echo "[2]"
	echo "[3]"
	echo "[4]"
	echo "q para salir"
	
	read valor

	if [ $valor == "1" ];then
		echo "entre 1"
	fi
	if [ $valor == "2" ];then
		echo "entre 2"
	fi
	if [ $valor == "3" ];then
		echo "entre 3"
	fi
	if [ $valor == "4" ];then
		echo "entre 4"
	fi

done
