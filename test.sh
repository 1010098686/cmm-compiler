#!/bin/bash

parser=parser

for file in $@; do
	result=${file%.cmm}.ir
	echo testing $file
	./$parser $file $result
done
