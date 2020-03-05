#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int sig)
{
   printf("SIGINT : signal caught : %d\n",sig);

}

void sigterm_handler(int sig)
{
   printf("SIGTERM : signal caught : %d\n",sig);

}


void sigkill_handler(int sig)
{
   printf("SIGKILL :: signal caught : %d\n",sig);

}

int main()
{

    int i;

		signal(SIGINT, sigint_handler);

		signal(SIGINT, sigterm_handler);
		
		signal(SIGINT, sigkill_handler);

		while(1)
		{
		   printf("running : %d\n", ++i);
			 sleep(1);
		
		}
return 0;
}
