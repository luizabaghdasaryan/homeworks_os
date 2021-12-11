#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/dir.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

void Count(const char* filename, const char* substring) {
	char path[256] = { '\0' };
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return;
	}
	struct stat info;
	if (stat(filename, &info) != 0)
	{
		return;
	}
	long int size = info.st_size;
	int n = size;
        char buff[size];
	read(fd, buff, size);
	int s_size = strlen(substring);
	if (s_size > size)
	{
		printf("Size of substring > file's size - wrong input!\n");
	}
	int counter = 0;
	char buff2[size];
	sprintf(buff2, "%c", buff[0]);

		for (int i = 1; i < size; ++i)
		{
			if ((strstr(buff2, substring)) != NULL)
			{
				++counter;
	                 	strcpy(buff2, "");
			}
			char ch[2];
			sprintf(ch, "%c", buff[i]);
			strcat(buff2, ch);
		}

	if (counter == 0)
	{
		printf("The given substring was not found \n");
	}
	else
	{
		printf("%s %d %s", "the given substring occurred", counter, "times \n");
	}
	close(fd);
}

int main(int argc, char* argv[]) {
	Count(argv[1], argv[2]);
	return 0;
}

