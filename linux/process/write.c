#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define SHMSIZE	10	//共享内存大小，10字节
#define SHMNAME "shmtest"	//共享内存名称

int main()
{
	int fd;
	char *ptr;

	//创建共享内存
	fd = shm_open(SHMNAME,O_CREAT|O_TRUNC|O_RDWR,S_IRUSR|S_IWUSR);
	if(fd < 0)
	{
		perror("shm_open error");
		exit(-1);
	}
	ftruncate(fd,SHMSIZE);	//设置大小为SHMSIZE

	//设置共享内存大小
	ptr = mmap(NULL,SHMSIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(ptr == MAP_FAILED)
	{
		perror("mmap error");
		exit(-1);
	}
	*ptr = 18;	//往起始地址写入18
	munmap(ptr,SHMSIZE);	//取消映射
	shm_unlink(SHMNAME);	//取消共享内存
	
	return 0;
}
