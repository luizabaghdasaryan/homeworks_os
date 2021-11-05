# 2. Получение и выдача списка файлов в заданной директории. 
#!/bin/bash
d_name=$1
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
			ls $elem
		else
		echo $elem
		fi
	done
fi

