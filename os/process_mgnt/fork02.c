#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(void)
{
		int ret;
    printf("main() started !!!\n");

    printf("pid: %d\n",getpid());

		ret = fork();

		if(ret == -1)
		{
			perror("fork() failed !!!\n");
			_exit(1);
		}

		printf("ret=%d\n", ret);

		printf("pid:%d\n",getpid());

		printf("main() exited !!!\n");

		return 0;

 


}
