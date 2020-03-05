#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
		int ret;
		int i;
		printf("main() started !!!\n");

		printf("pid: %d\n", getpid());

		ret=fork();
		if( ret== -1)
		{
				perror("fork() failed !!!\n");
				_exit(1);

		}

		if(ret==0)
		{
		     for(i=0; i<=40; i++)
		    {  

		         printf("child: %d\n",i);
						 sleep(1);
		
		    }  
		}
		else
		{
		   
		     for(i=0; i<=40; i++)
		    {  

		         printf("parent: %d\n",i);
						 sleep(1);
		
		    }  
		
		
		}
    
		printf("main() existed !!!!\n");
		return 0;
}
