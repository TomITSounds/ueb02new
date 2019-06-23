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

FILE *saveAppointment(FILE *Datei, TAppointment *Termin){
    fprintf(Datei,"<Appointment>\n");
    
    fprintf(Datei,"<Date>");
    fprintf(Datei,"%i.%i.%i",Termin->Date.Day,Termin->Date.Month,Termin->Date.Year);
    fprintf(Datei,"</Date>\n");
    
    fprintf(Datei,"<Time>");
    fprintf(Datei,"%i:%i:%i",Termin->Time.Hour,Termin->Time.Minute, Termin->Time.Second);
    fprintf(Datei,"</Time>\n");
    
    fprintf(Datei,"<Description>");
    fprintf(Datei,"%s",Termin->Description);
    fprintf(Datei,"</Description>\n");
    
    if(Termin->Location){
        fprintf(Datei,"<Location>");
        fprintf(Datei,"%s",Termin->Location);
        fprintf(Datei,"</Location>\n");
    }
    
    if(Termin->Duration){
        fprintf(Datei,"<Duration>");
        fprintf(Datei,"%i:%i:%i",Termin->Duration->Hour,Termin->Duration->Minute, Termin->Duration->Minute);
        fprintf(Datei,"</Duration>\n");
    }
    
    fprintf(Datei,"</Appointment>\n");

    return Datei;
}
