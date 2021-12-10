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

