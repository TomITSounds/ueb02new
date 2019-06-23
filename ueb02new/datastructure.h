//
//  datastructure.h
//  ueb01X
//
//  Created by Tom Mertens on 20.04.19.
//  Copyright © 2019 Tom Mertens. All rights reserved.
//

#ifndef datastructure_h
#define datastructure_h

#define MAX_APPOINTMENTS 100

typedef enum
{   NotADay, Mo, Tu, We, Th, Fr, Sa, Su}
TDayOfTheWeek;

typedef struct
{   int Day;
    int Month;
    int Year;
    TDayOfTheWeek DotW;
} TDate;

typedef struct
{   int Hour;
    int Minute;
    int Second;
} TTime;

typedef struct
{   TDate Date;
    TTime Time;
    char *Location;
    char *Description;
    TTime *Duration;
}   TAppointment;

extern TAppointment Calendar[];
extern int countAppointments;

#endif /* datastructure_h */
