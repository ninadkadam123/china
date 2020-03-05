#include<stdio.h>
#include<unistd.h>

int main()
{
   int ret,arr[2];
	 char str[20];

	 ret=pipe(arr);

	 if(ret<0)
	 {
			 perror("pipe() failed!!!");
			 _exit(2);
	 }


	 write(arr[1], "dac_pune",14);

	 read(arr[0], str,sizeof(str));

	 printf("read :%s\n",str);

	 close(arr[1]);

	 close(arr[0]);

return 0;
}
