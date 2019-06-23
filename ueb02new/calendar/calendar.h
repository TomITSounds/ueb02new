//
//  calendar.h
//  ueb02X
//
//  Created by Tom Mertens on 01.05.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#ifndef calendar_h
#define calendar_h

#include <stdio.h>
#include "../datastructure.h"

void sortCalendar(char *Title);
void searchAppointment(char *Title);
void listCalendar();
void getMenu(char **Menu);
void editAppointment(char *Title);
void createAppointment(char *title);
void deleteAppointment(char *Title);
void printAppointment(TAppointment *pTermin);
void printnextAppointment(TAppointment *pTermin);
void freeAppointment(TAppointment *App);
void freeCalendar();

#endif /* calendar_h */
