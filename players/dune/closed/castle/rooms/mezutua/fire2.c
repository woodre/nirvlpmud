inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if(!arg)
  {
    set_light(0);
    short_desc=("Door of Fire");
    long_desc=
"     Towering above you stand a huge set of obsidian doors. The door is\n"+
"open at the moment and through it, you see a pathway leading down to\n"+
"some unknown place. A glow of deep red emanates there.\n"+
"You hear tremblings sounds, and explosions.... As you look higher on the\n"+
"door, several words are scratched into a stone plaque. Upon the ground,\n"+
"several pieces of bone dot the obsidian floor, like the stars dot the night\n"+
"sky.\n";

    dest_dir=({
CASTLEROOM+"/lavapit.c","down"  ,
CASTLEROOM+"/smoke8.c","south"  ,
    });

    items=({
"doors", "     The door measures fourteen feet high, eight feet wide",
"door",  "     The door measures fourteen feet high, eight feet wide",
"bones", "     As you take a closer look at the bones, you see that they spell out\n"+
         "the following words:\n"+
         "   Unlike the sphere from ground to wall,\n"+
         "   The orbs must land short from tall.\n"+
         "   But which must happen first of all?",
"bone",  "     Why look at just one bone?",
"plaque","     When gems and jewels fill you with glee,\n"+
         "     Remember that punished you will be,\n"+
         "     If you touch the treasure you see",
    });
  }
}
