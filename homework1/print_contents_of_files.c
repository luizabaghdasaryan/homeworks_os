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
			FILE* fptr;
			printf("\n");
			printf("%s\n", entry->d_name);
		 	if(sub_dir==0)
			{
				char d_path[256] = { '\0' };
				strcpy(d_path, dirname);
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
		
			if (fptr == NULL)
			{
				return;
			}
			char c;
			while ((c = fgetc(fptr)) != EOF) {

				printf("%c", c);
			}
			fclose(fptr);
			printf("\n");
		}
	}

		closedir(dir);
}


int main() {
    traverseRecursive("lesson");
}

