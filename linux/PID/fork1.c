#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *env_init[] = {"USER=PENG","HOME=/home/peng/",NULL};//为子进程定义环境变量

int main(int argc,char *argv[])
{
        pid_t pid;
        if((pid = fork()) < 0)
        {
                perror("fork error");   //创建进程失败判断
        }
        else if(pid == 0)
        {
                execle("/home/peng/sample3","sample3","hello","world",(char *)0,env_init);//子进程转载新程序
                perror("execle error");
                exit(-1);
        }
        else
        {
                exit(0);        //父进程退出
        }

        return -1;
}
