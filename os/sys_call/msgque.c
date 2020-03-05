#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define MQ_KEY 0x2405

typedef struct mymsg
{
	long type;
	char str[20];
}mymsg_t;

int main(void)
{

	int ret, mqid, status;

	mqid=msgget(MQ_KEY, IPC_CREAT | 0600);

	if(mqid<0)
	{
	  perror("msgget() failed...");
		_exit(1);
	}
  
  ret=fork();

	if(ret==0)
	{
	     mymsg_t m1,m4;

			 printf("child: enter message :  ");
			 scanf("%s",m1.str);
			 m1.type=101;
			 msgsnd(mqid, &m1, sizeof(m1), 0);

			 printf("child waiting for message.....\n");
			 msgrcv(mqid, &m4,sizeof(m4),202,0);
			 printf("child received :%s\n ",m4.str);
	
	}
	else
	{
	  mymsg_t m2,m3;

		printf("parent waiting for message....");
		msgrcv(mqid, &m2, sizeof(m2),101,0);
		printf("parent received : %s\n",m2.str);

   printf("parent: Enter message: ");
	 scanf("%s",m3.str);
	 m3.type=202;
	 msgsnd(mqid, &m3,sizeof(m3),0);
  
	 wait(&status);

	 msgctl(mqid,IPC_RMID,NULL);

	  
	
	
	}






return 0;
}
