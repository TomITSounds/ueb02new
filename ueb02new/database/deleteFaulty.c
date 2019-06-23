//
//  deleteFaulty.c
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

int deleteFaulty(TAppointment *pCal){
    pCal->Date.Day = 0;
    pCal->Date.Month = 0;
    pCal->Date.Year = 0;
    pCal->Time.Hour = 99;
    pCal->Time.Minute = 99;
    pCal->Time.Second = 99;
    pCal->Description = NULL;
    pCal->Location = NULL;
    pCal->Duration = NULL;
    
    return 1;
}
