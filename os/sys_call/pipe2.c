#include<stdio.h>
#include<unistd.h>

#define RD 0
#define WR 1

int main(void)
{
   int ret, arr[2];

	 char str[20], buf[20];

	 pipe(arr);

	 ret=fork();

	 if(ret==0)
	 {
	    close(arr[0]);
			printf("child: enter the string\n");

      gets(buf);

			write(arr[1],buf,sizeof(buf));

	    close(arr[1]);
	 
	 }
  else
	{
	  close(arr[1]);



     read(arr[0], str,sizeof(str));
		 
		printf("parent: read from pipe \n %s\n",str);
		 close(arr[0]);

	
	}
return 0;
}
