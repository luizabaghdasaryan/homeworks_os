#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *args[] = {"cat", argv[1], NULL};
        int return_code = execv("/usr/bin/cat", args);
        if(return_code < 0) {
	printf("Error occured, %s\n", strerror(errno));
	return 1;
	}
	return 0;
}
