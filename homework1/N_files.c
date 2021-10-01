#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main() {
    char text[20];
    int N;
    scanf("%d \"%s\"", &N, text);
    for(int i=1; i<=N; ++i)
    {
            char name[15];
            sprintf(name, "%s%d%s","file_", i,".txt" );
            creat(name, S_IRWXU);
            char mes[20] = {'\0'};
            sprintf(mes, "%s%d%s","\"Hello world ", i, "\"");
	        int length = sizeof(mes) / sizeof(mes[0]);
            int fd = open(name, O_RDWR);
            write(fd, mes, length);
	    close(fd);
    }
}
