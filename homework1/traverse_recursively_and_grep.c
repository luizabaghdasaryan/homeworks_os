#include <stdio.h>

#include <string.h>

#include <fcntl.h>

#include <unistd.h>

#include <sys/dir.h>

#include <sys/types.h>

#include <sys/stat.h>

void traverseRecursive(const char* pathname, const char* string) {

	DIR* dir = opendir(pathname);



	if (!dir) {

		return;

	}

	char path_[256] = { '\0' };

	char d[256] = { '\0' };

	strcpy(path_, pathname);

	char* n = strchr(path_, '/');

	strcpy(d, n + 1);

	printf("%s \\\n", d);



	struct dirent* entry;

	char path[256] = { '\0' };

	int sub_dir = 0;

	char path1[256] = { '\0' };

	while ((entry = readdir(dir))) {

		if (entry->d_type == DT_DIR) {

			if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {

				++sub_dir;

				printf("%s \\\n", entry->d_name);

				strcpy(path, path_);

				strcat(path, "/");

				strcat(path, entry->d_name);

				traverseRecursive(path, string);

				--sub_dir;
			}

		}
		else

		{

			FILE* fptr;

			if (sub_dir == 0)

			{

				char d_path[256] = { '\0' };

				strcpy(d_path, path_);

				strcat(d_path, "/");

				strcat(d_path, entry->d_name);

				fptr = fopen(d_path, "r");

			}

			else

			{
				char p_path[256] = { '\0' };

				strcpy(p_path, path);

				strcat(p_path, "/");

				strcat(p_path, entry->d_name);

				fptr = fopen(p_path, "r");

			}

			char c;

			if (fptr == NULL)

			{

				return;

			}

			char line[300];

			int line_num = 1;

			while (fgets(line, sizeof line, fptr)) {

				if (strstr(line, string)) {

					if (line_num == 1)

					{

						printf("\n%s\n", entry->d_name);

					}

					printf(" %d %s\n", line_num, line);
					if (strchr(line, '\n')) {
						++line_num;
					}
				}
			}

			fclose(fptr);

			printf("\n");
		}
	}
	closedir(dir);
}
int main() {

	traverseRecursive("lesson/l", "include");

}
