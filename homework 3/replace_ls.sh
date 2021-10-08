#1.  Сохранить историю (history) терминала в файле и заменить все команды “ls” на “list directory”
#!bin/bash

cat /home/luiza/.bash_history > history.txt

sed 's/ls/list directory/' history.txt
