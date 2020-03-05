#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void)
{

		int ret;
		int status;

		printf("parent is started !!!!!\n");
		ret = fork();

		if( ret == -1)
		{
		    perror("fork() failed !!!!\n");
				_exit(1);
		}

		if(ret ==0)
		{
		    char *args[] = {"ls" , "-l" , "-l" , "/home/sunbeam" , NULL};
				int err = execvp("ls" , args);
         if(err == -1)
				 {
				      perror("exec() failed!!!!\n");
							_exit(1);
				 }
		
		}
		else
		{
				   wait(&status);
					 printf("parent is terminated");
		}


     return 0;
}
