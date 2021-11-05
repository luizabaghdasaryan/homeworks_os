#1. Замена существующего расширения в имени файла на заданное. Исходное имя файла и новое расширение передаются скрипту в качестве параметров
#!/bin/bash
filename=$1
ext=$2
if [[ -z $filename ]] || [[ -z $ext ]] 
then
	exit 1
fi

if [[ ! -f "$filename" ]]
then 
	echo "File \"$filename\" doesn't exist!"

else
	echo "original filename: $filename"
	#filename_="${filename%%.*}"
	#echo "renamed filename: $filename_.$ext"
	filename_=`echo "$filename" | sed -e 's/\..*//' -e 's/$/'.$ext'/'`
	mv $filename $filename_
fi
