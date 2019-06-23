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
#include <string.h>

/***************************************************************************
 Funktion:  createAppointment
 Parameter: char *title
 Ergebnis:  void
 Beschreib: erstellt einen neuen Termin am naechsten freien Platz im Kalendar array
 ***************************************************************************/

void createAppointment(char *title)
{   TTime scanDuration;
    scanDuration.Hour = 0;  //0 Initialisierung
    scanDuration.Minute = 0;
    scanDuration.Second = 0;
    
    TAppointment *Input = &Calendar[countAppointments];
    
    clearScreen();
    if(countAppointments <= MAX_APPOINTMENTS)
    {   printf("%s\n",title);
        printLine('=', strlen(title));
        printf("\n");

        while(!getDate("Datum:            ",&Input->Date))
            ;
        while(!getTime("Uhrzeit:          ",&Input->Time))
            ;
        getText("Beschreibung:     ",100,&Input->Description, 0);
        while(!getText("Ort:              ",15,&Input->Location, 1))
            ;
        
        //Input->Duration = NULL;
        if (getTime("Dauer:            ", &scanDuration)){
            Input->Duration = malloc(sizeof(TTime));
            if(Input->Duration){
                *(Input->Duration) = scanDuration;
            }
            //else "Alles Scheisse?"
        }
        countAppointments ++;
        printf("Termin wurde gespeichert!\n\n");
    }
    else
        printf("Speicher voll. Es koennen keine weiteren Termine gespeichert werden.\n");
    
    printf("Bitte Enter-Taste druecken.");
    waitForEnter();
}

