//pipe1.c
// 두 프로세스간 통신을 위해 파이프 생성
// 파이프는 별도의 방법으로만 이용할 수 있음

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#define BUF_SIZE 30

int main(int argc, char *agrv[])
{
    int fds[2];
    char str[]="Who are you?";
    char buf[BUF_SIZE];
    pid_t pid;

    pipe(fds);
    pid=fork();
    if (pid==0)
    {
        write(fds[1], str, sizeof(str));
    }
    else
    {
        read(fds[0], buf, BUF_SIZE);
        puts(buf);
    }
    return 0;
}