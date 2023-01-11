#!/bin/bash

exe="../../bin/splc"
testPath="given"
givenFiles=`ls $testPath/in`

array=(${givenFiles// / })

for var in ${array[@]}
do
   filename=`expr substr "$var" 1 10`
   echo $filename
   $exe $testPath/in/$var
done
mv $testPath/in/*.ir $testPath/out/


