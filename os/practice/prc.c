#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(void)
{

	int ret;
	int i;
	int status;

	printf("main() started!!!\n");

	
			ret=fork();
 
			if(ret ==-1)
			{
			  perror("fork() failed!!!\n");
				_exit(1);
			
			}

  if(ret == 0)
	{
 
		char *args[]={"ls", "-l", "-i", "/home/sunbeam", NULL};
		int err=execvp("ls",args);
				if(err==-1)
				{
				
				     perror("exec() failed!!!!");
						 _exit(1);
				
				}


 }
	else
	{
	
		
					  wait(&status);
					
				printf("parent is exited!!!\n");		
	}
				printf("main() exited!!\n");

return 0;
}
