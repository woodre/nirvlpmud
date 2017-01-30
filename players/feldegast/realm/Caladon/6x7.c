/*
File: 6x7.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/14/02
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  x=6; y=7;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  This is a patch of hilly grassland between a road to the west and\n\
a forest to the east.  The road extends from north to south.  To the\n\
south of you is a hill with a bluish light atop it.\n";
  items=({
    "grassland", "reflexive",
    "road",      "The road is well-paved and extends from north to south",
    "forest",    "The foothills to the east are thick with trees",
    "hill",      "The hill is the tallest for the miles around.  A bluish light is at its peak",
    "light",     "There is a bluish light at the top of the hill, but you can't make\n"+
                 "out any distinct shapes from here",
  });
  dest_dir=({
    PATH+"6x8.c","north",
    PATH+"5x6.c","west",
    PATH+"7x6.c","east",
    PATH+"6x6.c","south",
  });
}

