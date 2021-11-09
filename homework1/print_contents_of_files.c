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
    int sub_dir=0;//if =1, there are files of subdirectory
	while ((entry = readdir(dir))) {
		if (entry->d_type == DT_DIR) {
			if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
				++sub_dir;
				printf("%s \\\n", entry->d_name);
				strcpy(path, dirname);
				strcat(path, "/");
				strcat(path, entry->d_name);
				traverseRecursive(path);
				--sub_dir;
			}
	}

		else

		{

			char d[300]={'\0'};//content of directory file

			strcpy(d, dirname);

			strcat(d, "/");

		        char sb[300] = {'\0'};//content of subdirectory path

			strcat(sb, path);

		        strcat(sb, "/");

			if(sub_dir == 0)

			{
				printf("%s \n", entry->d_name);

				strcpy(d, entry->d_name);

				int f1 = open(d, O_RDONLY);

				char d_f[300] = {'\0'};

				read(f1, d_f, 300);

				for(int i = 0; i < sizeof(d_f); ++i)

				{

					printf("%c", d_f[i]);

				}

			        printf("\n");	
			}

			else

			{

				printf("%s \n", entry->d_name);

				strcat(sb, entry->d_name);

				char sb_f[300] = {'\0'};

				int f2 = open(sb, O_RDONLY);

			        read(f2, sb_f, 300);

				for(int j = 0; j < sizeof(sb_f); ++j)

				{
					printf("%c", sb_f[j]);

				}

			}

		}
	}

		closedir(dir);
}


int main() {
    traverseRecursive(".");
}

