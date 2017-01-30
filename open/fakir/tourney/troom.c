#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+"Grand Tournament of Nirvana"+NORM;
  long_desc=
    "The inner stone walls of the arena are covered in a light colored\n"+
    "fungus and water drips from the upper columns.  A stone stairway\n"+
    "leads to the open spectator stands above. Those who wish to join\n"+
    "in armed combat and possess the tournament amulet may 'touch' the\n"+
    "crossed swords on the arch to the north.  "+RED+"Beware...any items\n"+
    "in your inventory will be taken by the spirits of warriors past.  You may NOT take gear,\n"+
    "weapons nor heals inside the combat areas."+NORM+"  Gladiators may\n"+
    "not lay claim to any gear lost due to carelessness.\n";
  items=({
  });
  dest_dir=({
    "/room/vill_green.c","leave",
    PATH+"room2.c","north",
    PATH+"stands.c","up",
  });
}
