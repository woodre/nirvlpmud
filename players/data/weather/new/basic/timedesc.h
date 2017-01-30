/*
    basic/timedesc.h - some time description constants
    Mar 1992 by marion@cs.tu-berlin.de
    Many ideas from Foslay.
*/

#ifndef _basic_timedesc_h
#define _basic_timedesc_h

/*
    Two phases of the day:
    Day, night
    8-20 20-8
*/
#define TD_DAY_TWO	({28800,72000})

/*
    Eight phases of the day:
    Midnight, late night, morning, forenoon, noon, afternoon, evening, night.
    0-1       1-5         5-8      8-12      12-13 13-18      18-20    20-24
*/
#define TD_DAY_EIGHT	({0,3600,18000,28800,43200,46800,64800,72000})

#endif /* _basic_timedesc_h */
