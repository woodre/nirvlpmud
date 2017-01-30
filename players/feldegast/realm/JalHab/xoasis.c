#include "defs.h"

inherit MAPROOM;

void reset(int arg)
{
  object portal;
  if(!present("nomad"))
    move_object(clone_object(MON_PATH+"nomad.c"),this_object());
  if(arg)return;
  portal=clone_object("/players/feldegast/obj/azure_portal.c");
  portal->set_destination("/players/feldegast/shrine.c");
  move_object(portal,this_object());
  set_light(1);
  short_desc=CYN+"Oasis"+NORM;
  long_desc=
"  Rolling dunes surround an oasis in the middle of the Jal-Hab\n\
desert.  Towering palm trees providing cool shade and leafy shrubs\n\
surround a watering hole that is perhaps a dozen meters across.\n";
  dest_dir=({
    "blank","north",
    "blank","west",
    "blank","east",
    "blank","south",
  });
  items=({
    "dunes", "Dunes of sand rise and ebb across the desert",
    "oasis","This is an oasis in the middle of the Jal-Hab desert",
    "trees", "The palm trees provide some shade from the beating sun",
    "shrubs", "The shrubs surround the watering hole",
    "hole", "It is a small pond, perhaps three meters in diameter",
  });
}

