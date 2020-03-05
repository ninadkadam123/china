#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main(void)
{
int ret;
int i;

printf("main() started");

printf("pid : %d\n",getpid());

ret=fork();
if(ret==1)
{
   		perror("fork() failed!!!!\n");
			_exit(1);
}


if(ret== 0)
{
    for(i=1; i<=20;i++)
		{
		    printf("chil: %d\n",i);
				sleep(1);
			}
		printf("child is existed!!!!\n");
}
else
{
      for( i=0; i<40 ;i++)
			{
			   printf("parent: %d\n",i);
				 sleep(1);

			}
			printf("parent is existed!!!!\n");


}

printf("main() exited !!!!!\n");
return 0;
}
