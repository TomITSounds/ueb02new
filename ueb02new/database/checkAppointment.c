//
//  checkAppointment.c
//  ueb02
//
//  Created by Tom Mertens on 13.06.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../calendar/calendar.h"
#include "../datastructure.h"
#include "../datetime/datetime.h"
#include "../tools/tools.h"
#include "database.h"

int checkAppointment(TAppointment *pCal){
    if(pCal->Date.Day == 0)
        return 0;
    if(pCal->Date.Month == 0)
        return 0;
    if(pCal->Date.Year == 0)
       return 0;
    if(pCal->Time.Hour < 0 || pCal->Time.Hour > 23)
        return 0;
    if(pCal->Time.Minute < 0 || pCal->Time.Minute > 60)
        return 0;
    if(pCal->Time.Hour < 0 || pCal->Time.Hour > 60)
        return 0;
    if(pCal->Description == NULL)
        return 0;
    
    return 1;
}
