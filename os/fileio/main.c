/*
filename:main.c*/

#include<stdio.h>
#include<unistd.h>
#include"functions.h"

int main(void)
{
emp_t e1;
	int id;

	while(1)
	{
	   int choice= menu();
     switch(choice)
		 {
		   case EXIT:
				  _exit(0);
			 case ACCEP_RECORD:
					accept_employee_record(&e1);
					break;

			 case DISPLAY_RECORD:
				 display_employee_record(&e1);
					break;
		 
			 case WRITE_RECORD:
					write_record_into_file(&e1);
					break;
		 
			 case READ_RECORD:
					read_record_from_file();
					break;
		 
			 case UPDATE_RECORD:
					printf("enter the id");
					scanf("%d",&id);
					update_record(id);
					break;
		 
			 case DELETE_RECORD:
					printf("enter the id");
					scanf("%d",&id);
					delete_record(id);
					break;
		 }

	
	
	
	}


return 0;
}
