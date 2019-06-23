//
//  freeCalendar.c
//  ueb02
//
//  Created by Tom Mertens on 30.05.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include <string.h>
#include "../datastructure.h"
#include "calendar.h"

void freeCalendar(){
    int i;
    for(i=0; i<countAppointments; i++){
        freeAppointment(&Calendar[i]);
    }
}
