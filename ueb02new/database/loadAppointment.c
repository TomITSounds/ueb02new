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

FILE *loadAppointment(FILE *XML){
    char Zeile[101];
    Zeile[100] = '\0';
    char *pZeile;
    int len;
    TAppointment *pCal = Calendar + countAppointments;
    
    do{
        fscanf( XML, "%100[^\n^\r]", Zeile );
        fclearBuffer(XML);
        pZeile = Zeile;
        while ( (*pZeile == ' ') || (*pZeile == 9) )
            pZeile++;
        
        if(strncmp( pZeile, "<Date>", strlen("<Date>"))==0){
            len=strlen(pZeile)-(2*strlen("<Date>"))-1;
            pZeile += strlen("<Date>");
            if(strncmp(pZeile+len, "</Date>", strlen("</Date>")) == 0){
                getDateFromString(pZeile, &(pCal->Date));
            }
        }
        
        if(strncmp( pZeile, "<Time>", strlen("<Time>"))==0){
            len=strlen(pZeile)-(2*strlen("<Time>"))-1;
            pZeile += strlen("<Time>");
            if(strncmp(pZeile+len, "</Time>", strlen("</Time>")) == 0){
                getTimeFromString(pZeile, &(pCal->Time));
            }
        }
        
        if(strncmp( pZeile, "<Description>", strlen("<Description>"))==0){
            len=strlen(pZeile)-(2*strlen("<Description>"))-1;
            pZeile += strlen("<Description>");
            if(strncmp(pZeile+len, "</Description>", strlen("</Description>"))==0){
                pCal->Description = calloc(len+1, sizeof(char));
                if (pCal->Description != NULL){
                    strncpy(pCal->Description, pZeile, len);
            }
        }
        }
        
        if(strncmp( pZeile, "<Location>", strlen("<Location>"))==0){
            len=strlen(pZeile)-(2*strlen("<Location>"))-1;
            pZeile += strlen("<Location>");
            if(strncmp(pZeile+len, "</Location>", strlen("</Location>")) == 0){
                pCal->Location = calloc(len+1, sizeof(char));
                if (pCal->Location != NULL){
                    strncpy(pCal->Location, pZeile, len);
                }
            }
        }
        
        if(strncmp( pZeile,"<Duration>", strlen("<Duration>"))==0){
            len=strlen(pZeile)-(2*strlen("<Time>"))-1;
            pZeile += strlen("<Duration>");
            if(strncmp(pZeile+len, "</Duration>", strlen("</Duration>")) == 0){
                pCal->Duration = malloc(sizeof(TTime));
                if (pCal->Duration != NULL)
                    getTimeFromString(pZeile, pCal->Duration);
            }
        }
        
        if (feof(XML)){
            printf("Datei Fehlerhaft");
            deleteCalendarArray();
            freeCalendar();
            return XML;
        }
        
    }while (strncmp(pZeile, "</Appointment>", strlen("</Appointment>")) != 0);  //Haat auch mit falscher klammer funktioniert
        
    if (!checkAppointment(pCal)){
        freeAppointment(pCal);
        deleteFaulty(pCal);
        }
    else
        countAppointments ++;
    
    return XML;
}
