/*
filename : functions.h*/

#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include"emp.h"
enum menu_option{

EXIT, ACCEP_RECORD, DISPLAY_RECORD, WRITE_RECORD, 
READ_RECORD, UPDATE_RECORD, DELETE_RECORD };

int menu(void);
void write_record_into_file(emp_t *pe);
void read_record_from_file(void);
int update_record(int id);
void delete_record(int id);

#endif
