#!/bin/bash
d_name=$1
length=$2
if [[ ! -d $d_name ]]
then
        echo "$d_name not a directory"
else
        echo -e "\\ \n ${PWD##*/}"
        dir=$(ls $d_name)
        for elem in $dir
        do
                if [[ -d $elem ]]
                then
                        echo -e "\\ \n $elem"
			subdir=$(ls $elem)
			for el in $subdir
				
			do
				if [[ ${#el} -gt $length ]]
				then
					echo $el
				fi
			done
                else
			if [[ ${#elem} -gt $length ]]
			then
			       	echo $elem
			fi
                fi
        done
fi

