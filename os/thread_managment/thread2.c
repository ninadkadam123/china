#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *print_table(void* param)
{

    int i, num=(int )param;

	for(i=1;i<=10;i++)
	{
	   printf("%d\n",i*num);
		 sleep(1);
	
	}

	return NULL;


}


int main(void)
{
  pthread_t t1,t2;
	int i;
	pthread_create(&t1,NULL,print_table,(void*)10);

	pthread_create(&t2,NULL,print_table,(void*)20);

	for(i=0;i<5;i++)
	{
	
		printf("main: %d\n",i);
		sleep(1);
	}

	pthread_join(t1,NULL);

	pthread_join(t2,NULL);


return 0;
}
