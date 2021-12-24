#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if (pid < 0) {
        printf("[-] fork failed. %s\n", strerror(errno));
        return 1;
    }
    if (pid == 0) {
        sleep(2);
        pid_t child_pid = getpid();
		int fd = open("file.txt", O_CREAT | O_RDWR);
		if (fd == -1) {
			printf("Error occured, %s\n", strerror(errno));
			return 1;
		}
		write(fd, "Hi from child process", 21);
    } else {
        int status;
        pid_t child_pid = wait(&status);
		char buf[21];
		int fd = open("file.txt", O_RDONLY);
		if(fd == -1)
		{
			printf("Error occured, %s\n", strerror(errno));
                        return 1;
		}
		read(fd, buf, 21);
		printf("%s\n", buf);
        if (WIFEXITED(status)) {
            printf("[!] Child process status is %d\n", WEXITSTATUS(status));
        }
    }
    printf("[!] Done\n");
    return 0;
}


