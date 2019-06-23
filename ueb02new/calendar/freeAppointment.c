//
//  freeAppointment.c
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

void freeAppointment(TAppointment *App){
    free(App->Location);
    free(App->Description);
    if(App->Duration != NULL)
        free(App->Duration);
}
