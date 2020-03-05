#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(void)
{

      char cmd[256];
			char *cptr =NULL;
			char *args[32];
			int i=0;

			while(1)
			{
			
				i=0;

				printf("cmd>");
        gets(cmd);


				cptr=strtok(cmd,"");
				args[i]=cptr;


				do
				{
				    i++;
						cptr = strtok(NULL,"");
						args[i]=cptr;			
				}while(cptr != NULL);

				if(strcmp(args[0], "cd") == 0)
					   chdir(args[1]);
				else
					if(strcmp(args[0],"exit") == 0)
						_exit(0);
				else
				{
				     int status;

						 int ret =fork();

						 if(ret == -1)
						 {
						      perror("fork() failed !!!! ");
									_exit(1);
						 
						 }

						 if(ret == 0)
						 {
						     int err=execvp(args[0],args);
								 if(err == -1)
								 {
								    perror("exec() failed!!\n");
								    _exit(1);
								 }
						 
						 
						 }
						 else
						 {
						     
						  wait(&status);
						 
						 }
				}

			
			}


return 0;
}
