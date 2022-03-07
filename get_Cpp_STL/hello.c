#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> //이게 뭐임? 미친

int main(void){
    pid_t pid; //process_id

    pid = fork(); //부모 프로세스에서는 자식 프로세스의 PID값을 반환 받음
    printf("Hello, WSL!\n");
    return 0;
}