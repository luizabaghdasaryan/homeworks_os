#2. Написать программу, которая получает на вход имя файла и удаляет данный файл, если такой файл существует. Использовать Makefile для сборки программы.
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void RM_FILE(const char* filename)
{
	int result = unlink(filename);
	if (result == -1) {
		perror("");
	}
	else
		printf("removed\n");
}

int main(int argc, char* argv[])
{
	RM_FILE(argv[1]);
}
