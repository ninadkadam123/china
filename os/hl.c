#include<stdio.h>
#include<unistd.h>


int main(int argc, char *argv[])
{
 
 if(argc != 3)
 {
    printf("invlaid no of args!!!!");
		_exit(0);

 
 }

 printf("\n argc count is :: %d",argc);

 if((link(argv[1], argv[2])) != -1)
	 printf("hard link got created successfully....\n"); 

return 0;
}
