//
//  database.h
//  ueb02new
//
//  Created by Tom Mertens on 20.06.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#ifndef database_h
#define database_h

#include <stdio.h>

int checkAppointment(TAppointment *pCal);
int loadCalendar();
FILE *loadAppointment(FILE *XML);
int saveCalendar();
FILE *saveAppointment(FILE *Datei, TAppointment *Termin);
void deleteCalendarArray();
int deleteFaulty(TAppointment *pCal);


#endif /* database_h */
