#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>
#include <errno.h>

#define MAPSIZE 100	/*共享内存大小，100字节*/
int main(int argc,char **argv[])
{
	int shmid;
	char *ptr;
	sem_t *semid;
	if(argc != 2){
		printf("usage: %s<pathname>\n",argv[0]);/*参数argv[1]指定共享内存和信号量的名字*/
		return -1;
	}

	shmid = shm_open(argv[1],O_RDWR,0);	/*打开共享内存对象*/
	if(shmid == -1){
		printf("open shared memory error.\n");
		return -1;
	}

	ftruncate(shmid,MAPSIZE);	/*设置共享内存大小*/
					/*将共享内存进行映射*/
	ptr = mmap(NULL,MAPSIZE,PROT_READ|PROT_WAITE,MAP_SHARED,shmid,0);

	semid = sem_open(arg[1],0);	/*打开信号量对象*/
	if(semid == SEM_FAILED){
		printf("open semaphore error\n");
		return -1;
	}
	printf("client input");
	fgets(ptr,MAPSIZE,stdin);	/*从标准输入读取需要写入共享内存的值*/
	sem_post(semid);	/*通知服务器*/

	munmap(ptr,MAPSIZE);	/*取消共享内存的映射*/
	close(shmid);
	sem_close(semid);

	return 0;
}
