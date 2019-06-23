/***************************************************************************
 Funktion:      printAppointment
 Parameter:     TAppointment *pTermin
 Ergebnis:      void
 Beschreib:     Druckt einen Termin mit Datum aus
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../datastructure.h"
#include "../datetime/datetime.h"
#include "../tools/tools.h"
#include "calendar.h"

void printAppointment(TAppointment *pTermin)
{
    //Dieser Block kommt spaeter in die list Calendar, wenn wir die Termine nach Datum sortieren
    printDate(&pTermin->Date);
    printf(":\n");
    printLine('-',15);

    printf("\t");
    printTime(&pTermin->Time);
    
    if (pTermin->Location)
        printf(" -> %-15s | ", pTermin->Location);
    else
        printf(" ->                 | ");
    
    if(strlen(pTermin->Description) > 48)
    {
        char *descr = pTermin->Description;
        int i;
        for(i = 0; i < 44; i++)
            printf("%c",*(descr+i));
        printf(" ...\n");
    }
    else
        printf("%s\n",pTermin->Description);
}
