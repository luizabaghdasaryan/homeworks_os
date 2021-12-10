№2. Написать программу, которая получает на вчод имя файла и удаляет данный файл, если такой файл существует. Использовать Makefile для сборки программы.
VAR=$(VAR_CMDLINE)
all: remove_file
	./remove_file $(VAR)

remove_file: rm_file.c
	gcc rm_file.c -o remove_file
