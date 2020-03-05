#include<stdio.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>

#define SHM_KEY 0x6236

typedef struct shm
{
   int cnt;
}shm_t;

shm_t var;

int main(void)
{
  shm_t *ptr=NULL;
	int ret, i, status,shmid;

	shmid = shmget(SHM_KEY, sizeof(shm_t), IPC_CREAT|0600);

	if(shmid < 0)
	{
	       printf("shmget() failed");
				 _exit(1);
	}

ptr=(shm_t*)shmat(shmid, NULL, 0);

if(ptr == (void*)-1)
{
  perror("shmat() failed");
	_exit(2);

}

ptr->cnt=0;
ret=fork();
if(ret==0)
{
    for(i=0;i<10;i++)
		{
			ptr->cnt++;
		  printf("child : %d\n",ptr->cnt);
      sleep(1);
		
		}
}
else
{
  
	for(i=0;i<10;i++)
	{
	  ptr->cnt--;
		printf("parent :%d\n",ptr->cnt);
		sleep(1);
	
	
	}
  
	wait(&status);

	printf("final count=%d\n",ptr->cnt);

	shmdt(ptr);

	shmctl(shmid,IPC_RMID,NULL);
}



return 0;
}

