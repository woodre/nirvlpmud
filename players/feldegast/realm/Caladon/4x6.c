/*
File: 4x6.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/15/02
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=4; y=6;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  A dirt path follows the line of a steap hill in the Caladonian\n\
countryside.  To the southeast you hear the distant sounds of the\n\
city.  Not far to the west you see a building.\n";
  items=({
    "hill", "The rolling foothills of Caladon are dotted with trees",
    "countryside", "reflexive",
    "city", "You cannot see that from here",
    "building", "You can't tell what it is from here",
    "path", "It leads east towards the highway and west towards a building",
  });
  dest_dir=({
    PATH+"3x6.c", "west",
    PATH+"5x6.c", "east",
    PATH+"4x5.c", "south",
  });
}

