/*
filename:function.c*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include"functions.h"

int menu()
{
   int choice;

	 printf("0. exit\n");
   printf("1. accept record\n");
	 printf("2. display record\n");
	 printf("3. write record into file\n");
	 printf("4. read all record from file \n");
	 printf("5. update record\n");
	 printf("6. delete record\n");
	 printf("enter the choice: \n");
	 scanf("%d",&choice);

	 return choice;
	 

}


void write_record_into_file(emp_t *pe)
{
   int fd=open("empdb.db", O_CREAT|O_RDWR|O_APPEND, 0644);;
	 if(fd==-1)
	 {
	   perror("open() failed!!!!!");
		_exit(1);
	 }
    
  write(fd, pe, sizeof(emp_t));

	close(fd);


}

void read_record_from_file(void)
{
   emp_t e;

	 int fd=open("empdb.db",O_RDONLY);
	 if(fd==-1)
	 {
	    perror("open() failed!!!!");

	 }
	 
	 while(read(fd,&e,sizeof(emp_t))>0)
	 {
	 display_employee_record(&e);
	 
	 }

  close(fd);
}




int update_record(int id)
{
   emp_t e;
	 long int offset  =sizeof(emp_t);
	 int update=0;

   int fd=open("empdb.db",O_RDWR);
	 if(fd==-1)
	 {

		 perror("open() failed !!!!");
		 _exit(1);
	 
	 }


	 while(read(fd,&e,sizeof(emp_t))>0)
	 {
	 
      if(e.empid==id)
			{
			
            display_employee_record(&e);

						accept_employee_record(&e);


						lseek(fd,-offset,SEEK_CUR);	

						write(fd,&e,sizeof(emp_t));

						update=1;
						break;

			}

	 
	 }

	 close(fd);

	 return update;



}


void delete_record(int id)
{
  emp_t e;
 
	 int fs=open("empdb.db", O_RDONLY);
	 int fd=open("temp.db", O_CREAT|O_WRONLY, 0644);

	 if(fs == -1)
	 {
	    perror("open() failed!!!!");
      _exit(1);
	 }

	     while(read(fs,&e,sizeof(emp_t))>0)
			 {			  
			 if(e.empid!=id)
			 {	
			    write(fd, &e, sizeof(emp_t));
       } 
			 }
			 close(fs);
		close(fd);

		unlink("empdb.db");

		
		rename("temp.db","empdb.db");

		
		
		}

