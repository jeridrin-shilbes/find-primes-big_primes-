#!/bin/bash
format()
{
    if [ $# -ne 1 ];then
        echo "error ocurred: formatting"
        return 0
    fi
    if [ "$1" -gt 1000 ];then
        if [ "$1" -gt 60000 ];then
            echo -n "$(( $1 / 60000)) mins : "
        fi
        echo -n "$(( ($1 / 1000) % 60 ))"
    else echo -n "0"
    fi
    if [[ $(( $1 % 1000 )) -gt 0 ]] ;then 
        echo -n  ".$(( $1 %1000 ))"
    fi
    echo " secs"
}
gcc serveofprimeV3.c -o primeV3
declare -a lg
for ((i=0;i < 2;i++)){
tm1=$(python3 timeteller.py)
time ./primeV3  
tm2=$(python3 timeteller.py)
tm_taken=$(( tm2 - tm1 ))
lg[i]=$tm_taken
}
unset "lg[0]"
sum=0
for tm in "${lg[@]}";do
(( sum+= "$tm"))
done
format $(( sum / ${#lg[@]} ))

