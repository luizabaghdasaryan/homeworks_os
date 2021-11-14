 /*2.Написать программу, которая рекурсивно обходит заданную директорию и печатает содержимое каждого файла с новой строки.*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/dir.h>
#include <sys/types.h>
#include <sys/stat.h>

void traverseRecursive(const char* dirname) {

	DIR* dir = opendir(dirname);
	if (!dir) {

		return;
	}

	printf("%s \\\n", dirname);

        struct dirent* entry;

	char path[256] = { '\0' };

	strcpy(path, dirname);

	strcat(path, "/");

	while ((entry = readdir(dir))) {

		if (entry->d_type == DT_DIR) {

			if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {

					strcat(path, entry->d_name);

					traverseRecursive(path);

					strcpy(path, dirname);

					strcat(path, "/");
			}

	}

		else
		{

			printf("%s \n", entry->d_name);

			char d[300]={'\0'};//path of the current file

			strcpy(d, path);

		        strcat(d, "/");

			strcat(d, entry->d_name);

			struct stat info;

			stat(d, &info);

			long int size = info.st_size;

			int fd = open(d, O_RDONLY);

			char f[size];//buff for file's content

			read(fd, f, size);

			for(long int i = 0; i < size; ++i)

			{

				printf("%c", f[i]);

			}

			printf("\n");

			close(fd);

		}

	}

		closedir(dir);

}

int main() {

    traverseRecursive(".");

    return 0;

}

