#include "/players/catacomb/misc/ansi.h"
#define TP this_player()

inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Second level of the Durkor Caverns" ;
  long_desc =(
  "  The room opens up to a set of stairs leading deeper into the cavern.\n"+
  "The sounds of metalworking can be heard further down the stairs.  Several\n"+
  "magical balls of light line the stairway leading down.  The outcropping\n"+
  "of rocks at the top of the room seems to be rather disturbing.  The shelf\n"+
  "appears to be the best spot for a lookout.\n"); 

  items = ({
    "stairs",
    "The stairs lead down further into the Durkor caverns",
    "stairway",
    "The stairway leads down further into the Durkor caverns",
    "light",
    "The balls of light follow the stairs deeper into the caverns", 
    "balls",
    "The balls of light follow the stairs deeper into the caverns", 
    "ball",
    "The balls of light follow the stairs deeper into the caverns",
    "outcropping",
    "A large outcropping is at the top of the cavern several feet above the ground",
    "rocks",
    "The rocks form an outcropping at the top of the cavern several feet above the ground",
  });

  dest_dir = ({
    "/players/catacomb/Cavern/rooms/lvl2_11.c","east",
    "/players/catacomb/Cavern/rooms/lvl3_1.c","stairs"
  });
}
