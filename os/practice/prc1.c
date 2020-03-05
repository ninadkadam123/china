#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main(void)
{

	int pos;

	int fd=open("empdb.db",O_RDONLY);

	pos=lseek(fd,0,0);
	printf("pos=%d\n",pos);


	pos=lseek(fd,-20,2);
	printf("pos=%d\n",pos);

	pos=lseek(fd,-50,1);
	printf("pos=%d\n",pos);
return 0;
}

