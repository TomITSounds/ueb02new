//
//  deleteCalendarArray.c
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

void deleteCalendarArray(){
    for(int i=0; i<MAX_APPOINTMENTS; i++)
        deleteFaulty(&Calendar[i]);
}
