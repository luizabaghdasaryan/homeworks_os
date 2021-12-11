VAR=$(VAR_CMDLINE)
all: remove_file
	./remove_file $(VAR)

remove_file: rm_file.c
	gcc rm_file.c -o remove_file
