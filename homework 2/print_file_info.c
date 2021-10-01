#include <stdio.h>

#include <string.h>

#include <fcntl.h>

#include <unistd.h>

#include <sys/dir.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <time.h>



void printTimeInfo(const char* filename) {

	if (!filename) {

		return;

	}

	struct stat info;

	stat(filename, &info);

	struct tm timeInfo = *localtime(&info.st_ctime);

	printf("%s -> ", filename);

	printf("%d/%d/%d | ", timeInfo.tm_mday, timeInfo.tm_mon + 1, timeInfo.tm_year + 1900);

	printf("%d:%d:%d", timeInfo.tm_hour, timeInfo.tm_min, timeInfo.tm_sec);

	if (!(S_ISDIR(info.st_mode))) {

	printf(" | %ld bytes", info.st_size);

	}

	printf(" \\\n");

}



void traverseRecursive(const char* dirname) {

	DIR* dir = opendir(dirname);



	if (!dir) {

		return;

	}

	printTimeInfo(dirname);

	int sub_dir = 0;

	char path[256] = { '\0' };

       	struct dirent* entry;



	while ((entry = readdir(dir))) {

		if (entry->d_type == DT_DIR) {

			if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {

				++sub_dir;

				strcpy(path, dirname);

				strcat(path, "/");

				strcat(path, entry->d_name);

				//printTimeInfo(path);

				traverseRecursive(path);

				--sub_dir;

			}

		}



		else

		{

			if (sub_dir == 0)

			{

				char d_path[256] = { '\0' };

				strcpy(d_path, dirname);

				strcat(d_path, "/");

				strcat(d_path, entry->d_name);

				printTimeInfo(d_path);

			}

			else

			{

				char p_path[256] = { '\0' };

				strcpy(p_path, path);

				strcat(p_path, "/");

				strcat(p_path, entry->d_name);

				printTimeInfo(p_path);



			}

			

		}

	}

			



		closedir(dir);

}





int main(int argc, char* argv[]) {

    traverseRecursive(argv[1]);

}
