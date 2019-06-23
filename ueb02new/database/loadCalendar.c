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
int loadCalendar()
{   char Zeile[101];
    Zeile[100] = '\0';
    char *pZeile;
    FILE *XML;
    
    XML = fopen("/Users/tomtom/calendar/calendar.xml", "r");
    
    if(!XML)
        return 0;
    
    do
    {   
        fscanf( XML, "%100[^\n]", Zeile );
        fclearBuffer(XML);
        pZeile = Zeile;
    
        while ( (*pZeile == ' ') || (*pZeile == 9) )
            pZeile++;
        
        if ( feof( XML ) ){
            printf("Datei Fehlerhaft");
            deleteCalendarArray();
            freeCalendar();
            waitForEnter();
            return 0;
        }
       
        if (strncmp(pZeile, "<Appointment>", strlen("<Appointment>")) == 0)
            XML = loadAppointment(XML);
        
    } while (strncmp(pZeile, "</Calendar>", strlen("</Calendar>")) != 0);

    fclose(XML);
    return 1;
}
