/*
File: 3x8.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 10/24/01
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);

  if(arg) return; /* Intentional. */

  if(!random(4) && !present("oak tree"))
    move_object(clone_object(MON_PATH+"tree.c"), this_object());

  x=3; y=8;
  set_light(1);

  short_desc=AREANAME;
  /* Lazy, lazy, lazy. */
  long_desc=
"  The land here is filled with rolling hills and scraggly trees that\n\
just barely cling to life.  To the north of you is the River Siber and\n\
to the south an iron fence blocks further travel.\n";

  items=({
    "river", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "siber", "The river is about two stones' throws across and much\n"+
             "too deep to cross",
    "hills", "The hills here are covered with diseased and rotting trees",
    "hill", "The hills to the south of you are dotted with trees",
    "trees", "The trees here are scraggly looking and diseased, with little foliage\n"+
             "and twisted and bent bodies",
    "fence", "The fence is made out of cast iron and ten feet tall.  It does not\n"+
             "appear to be climbable",
  });

  dest_dir=({
    PATH+"3x9.c", "north",
    PATH+"2x8.c","west",
    PATH+"4x8.c","east",
  });
}

