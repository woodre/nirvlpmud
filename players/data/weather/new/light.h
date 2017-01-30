#ifndef _sys_light_h
#define _sys_light_h

// squared all values, Coogan, 02-Jun-99

#define LIGHT_CANDLE       1000  //  30
#define LIGHT_TORCH        5000  //  60
#define LIGHT_LAMP        15000  // 120

#define LIGHT_DARKNESS_THRESHOLD        1000 //   10 // lowered it 5000 -> 1000

#if 0  /* this value is meant to be the upper threshold which eyes of
        * normal livings can reach in adaptation.  so a value which
        * makes most livings be on the upper threshold all the time
        * does not make much sense.
        * this is the abstract reason i raised this value.  the concrete
        * reason was a flashlight which wasn't able to make people to
        * adapt to much higher values (and thus blinding them for a while
        * after going dark again), as people wouldn't adapt to such values,
        * being at their upper border already.
        *                                      Alfe 2002-Mar-13
        */
#  define LIGHT_BRIGHTNESS_THRESHOLD 1500000 // 12000 //        Alfe 2002-Mar-8
             // lowered again, not back to 1.4M, but to 1.5M, Coogan, 11-Mar-02
#else
#  define LIGHT_BRIGHTNESS_THRESHOLD 140000000
#endif

// these two values are used at adaptation of eyes to surrounding light levels.
// if a living is adapted perfectly to a room with light level X, then it
// will be able to see in rooms with light level
// X/LIGHT_DARKNESS_TOLERANCE .. X*LIGHT_BRIGHTNESS_TOLERANCE
#define LIGHT_DARKNESS_TOLERANCE 10
#define LIGHT_BRIGHTNESS_TOLERANCE 20  // more tolerance upwards than downwards

// below X/LIGHT_DARKNESS_MARGIN and above X*LIGHT_BRIGHTNESS_MARGIN
// a living will not see _everything_ but just a part of the things.
#define LIGHT_DARKNESS_MARGIN 9
#define LIGHT_BRIGHTNESS_MARGIN 18

// the next values are permille values;
// example: a dense forest would receive 200 permille of that at noon
#define LIGHT_F_INSIDE         500
#define LIGHT_F_FOREST_LIGHT   800
#define LIGHT_F_FOREST_NORMAL  600
#define LIGHT_F_FOREST_DENSE   400
#define LIGHT_F_DESERT_ICE    1600
#define LIGHT_F_DESERT_SAND   1300
#define LIGHT_F_DESERT_ROCK   1100
#define LIGHT_F_UNDERGROUND    100
#define LIGHT_F_MOUNTAIN      1100
#define LIGHT_F_UNDER_WATER    500
#define LIGHT_F_VILLAGE       1200  // Coogan, 05-Oct-99, only used at night

#endif // _sys_light_h
