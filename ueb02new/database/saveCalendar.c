//
//  loadCalendar.c
//  ueb02new
//
//  Created by Tom Mertens on 20.06.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include "../calendar/calendar.h"
#include <stdio.h>
#include "../datetime/datetime.h"
#include "../tools/tools.h"
#include "../datastructure.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "database.h"
int saveCalendar(){
    FILE *XML;
    TAppointment *pCal = Calendar;
    int i;
    XML = fopen("/Users/tomtom/calendar/calendar.xml", "w");
    
    if(!XML)
        return 0;
    
    fprintf(XML, "<Calendar>\n");
    for(i=0; i<countAppointments; i++)
        XML = saveAppointment(XML, pCal++);
        
    fprintf(XML, "</Calendar>\n");
    
    fclose(XML);
    
    return 1;
}
