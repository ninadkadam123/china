/*
filename: emp.h*/

#ifndef __EMP_H
#define __EMP_H

typedef struct  employee
{
   int empid ;
	 char name[32];
	 float salary;


}emp_t;

void accept_employee_record(emp_t *pe);
void display_employee_record(emp_t *pe);

#endif
