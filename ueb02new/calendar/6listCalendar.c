//
//  calendar.c
//  ueb02X
//
//  Created by Tom Mertens on 01.05.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include "calendar.h"
#include <stdio.h>
#include "../datetime/datetime.h"
#include "../tools/tools.h"
#include "../datastructure.h"
#include <stdlib.h>
#include <math.h>

/***************************************************************************
 Funktion:
 Parameter:
 Ergebnis:
 Beschreib:
 ***************************************************************************/
void listCalendar()
{
    clearScreen();
    printf("Liste der Termine\n");
    printLine('=',17);
    printf("\n");
    
    int i = 0, countSame = 0;
    int stop = 0;
    int count = countAppointments;
    
    TAppointment *next = Calendar, *first = Calendar;
    do
    {   stop += 15;
        if(count < 15)
            stop = countAppointments;
        
        for( ;i < stop; i++)
        {
            printLine('=',78);
            printAppointment(first);
            count--;
            next = first +1;
            
            while(next->Date.Day == first->Date.Day
                  && next->Date.Year == first->Date.Year
                  && next->Date.Month == first->Date.Month ){
                printnextAppointment(next);
                next++;
                countSame++;            //Zaehler fuer Termine mit gleichem Datum
                count--;
                i++;
            }
            if(countSame){
                first += countSame;
                countSame=0;
            }
            first++;
        }
        printf("Weiter mit Enter\n");
        waitForEnter();
    } while(count > 0);
}
