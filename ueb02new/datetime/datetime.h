#ifndef DATETIME_H
#define DATETIME_H DATETIME_H
#include "../datastructure.h"


int isLeapYear(int year);
int isDateValid(TDate *Date);
int isTimeValid(TTime *Time);
int getDateFromString(char *Input, TDate *Date);
int getTimeFromString(char *Input, TTime *Time);
int askYesOrNo(char *Prompt);
int getDate (char*Prompt, TDate*Date);
int getTime (char*Prompt, TTime*Time);
void printDate(TDate *Date);
void printTime(TTime *Time);

#endif
