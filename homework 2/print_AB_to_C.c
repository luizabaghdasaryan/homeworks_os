/*2. Написать программу на Си, которая получает на вход 2 файла A и B. Далле открывает/создает новый файл C и копирует содержимое первого
файла A в файл C, после чего добавляет содержимое второго файла B в конец файла C.*/


#include <stdio.h>

#include <string.h>

#include <fcntl.h>

#include <unistd.h>

#include <sys/dir.h>

#include <sys/types.h>

#include <sys/stat.h>





void AB_to_C(const char* file1, const char* file2) {

	char c;

	char s[2];

	int fd = open("f3", O_CREAT | 774);

	

	if (fd < 0)

	{

		return;

	}

	FILE* f1 = fopen(file1, "r");

	if(!f1)

	{

		return;

	}

	while ((c = fgetc(f1)) != EOF) {

		sprintf(s, "%c", c);



		write(fd, s, 1);



	}

	lseek(fd, -1, SEEK_END);

	FILE* f2 = fopen(file2, "r");

	if(!f2)

	{

		return;

	}

	while ((c = fgetc(f2)) != EOF) {

		sprintf(s, "%c", c);



		write(fd, s, 1);

	}

	fclose(f1);

	close(fd);

	fclose(f2);

}



/*int main() {

	AB_to_C("f1", "f2");

}*/



int main(int argc, char* argv[])

{

	AB_to_C(argv[1], argv[2]);

}

