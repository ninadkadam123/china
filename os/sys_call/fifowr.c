#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{

	int fw;;

  fw=open("dac_fifo",O_WRONLY);
	if(fw<0)
	{
			perror("open failed..");
			_exit(1);

	}

	write(fw,"SunBeam",7);

	close(fw);

return 0;
}
