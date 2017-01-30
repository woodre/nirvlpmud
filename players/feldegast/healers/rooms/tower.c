#include "def.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_no_teleport(1);
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  The top of the Healer Hall offers an impressive vista of the\n\
surrounding countryside.  A Wind blows over the tower, threatening\n\
to knock off the unwary.  An enclosed staircase leads back down into\n\
the keep.\n";
  items=({
    "top",         "A stone tower thrusts up out of the keep of the Healer Hall, offering\n"+
                   "an impressive vista of the surrounding countryside",
    "hall",        "A stone tower thrusts up out of the keep of the Healer Hall, offering\n"+
                   "an impressive vista of the surrounding countryside",
    "healer hall", "A stone tower thrusts up out of the keep of the Healer Hall, offering\n"+
                   "an impressive vista of the surrounding countryside",
    "tower",       "A stone tower thrusts up out of the keep of the Healer Hall, offering\n"+
                   "an impressive vista of the surrounding countryside",

    "countryside", "To the south you can make out a river flowing from west to east.  To the\n"+
                   "southeast you can see a city, and to the north you can see two towers",
    "vista",       "To the south you can make out a river flowing from west to east.  To the\n"+
                   "southeast you can see a city, and to the north you can see two towers",
    "towers",      "The eastern tower has a bright, glinting crystal at its peak, and the western\n",
                   "tower casts a black shadow",
    "staircase",   "The staircase leads back down into the keep",
    "keep",        "The keep sits in the middle of the Healer Hall's sprawling compound",
  });
  dest_dir=({
    ROOMPATH+"east_hall","down",
  });

  /* Healer Hall trainers appear here randomly. THIS IS INTENTIONAL. */

  if(!random(5))
    move_object(clone_object(NPCPATH+"elisia.c"), this_object());
}

