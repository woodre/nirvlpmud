/*
File: cave3.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/22/02
Description:
  Barony of Caladon
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  object corpse;
  ::reset(arg);
  if(arg) return;
  corpse = clone_object("/obj/corpse.c");
  corpse->set_name("giant spider");
  corpse->set_level(19);
  move_object(corpse, this_object());
  set_light(0);
  short_desc=AREANAME;
  long_desc=
"  The sun shines dimly through a hole in the ceiling.  A tree trunk\n\
sticks through the hole at a diagonal angle.  Bits of turf and leaves\n\
cover the floor of this huge cave.  A tunnel leads southeast through\n\
the rock.\n";
  items=({
    "cave", "The cave is approximately twenty meters across and shaped\n"+
            "like an egg",
    "sun", "You can't make it out from here",
    "ceiling", "The ceiling of the cave appears to consist of dirt and rock.\n"+
               "It doesn't appear to be stable",
    "tree", "It appears to have fallen into the hole at an angle.  You can\n"+
            "use it to go back up to the surface",
    "hole", "The hole in the ceiling is roughly ten meters in diameter",
    "angle", "The tree descends through the hole in the ceiling at an\n"+
             "approximately 45 degree angle",
    "turf", "You assume these are the remains of the ceiling",
    "leaves", "You assume these fell from the surface",
    "floor", "The floor is covered in bits of turf and leaves",

  });

  dest_dir=({
    PATH+"7x8.c", "up",
    PATH+"cave4.c", "east",
  });
}
