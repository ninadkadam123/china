#include<stdio.h>


int main(int argc, char *argv[], char *envp[])
{
      int i=0;

  /*		while(envp[i]!=NULL)
			{
			     printf("envp[%d]: %s\n", i, argv[i]);
					 i++;
			
			
			
			}*/

   while(argv[i]!=NULL)
	 {
	    printf("argv[%d]: %s \n",i,argv[i]);
			i++;
	 
	 }


 return 0;

}
