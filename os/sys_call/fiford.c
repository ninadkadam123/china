#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
  int fr;
   char str[20];
	fr=open("dac_fifo",O_RDONLY);
	if(fr<0)
	{
	  perror("open() failed....\n");
		_exit(1);

	}

   read(fr,str,sizeof(str));

	 printf("\n %s \n",str);

	 close(fr);
	 return 0;

}
