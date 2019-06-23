/***************************************************************************
 Funktion:      printAppointment
 Parameter:     TAppointment *pTermin
 Ergebnis:      void
 Beschreib:     Druckt einen Termin ohne Datum aus im anschluss an einen Termin
                mit gleichem Datum
 ***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../datastructure.h"
#include "../datetime/datetime.h"
#include "../tools/tools.h"
#include "calendar.h"

void printnextAppointment(TAppointment *pTermin){
    
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
        {
            printf("%c",*(descr+i));
        }
        printf(" ...\n");
    }else
    {
        printf("%s\n",pTermin->Description);
        }
    }
