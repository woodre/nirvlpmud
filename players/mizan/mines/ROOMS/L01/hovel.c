inherit "/room/room.c";
#include "/obj/ansi.h"

object bigbunny;

void reset(int arg) 
{

   if(!bigbunny)
   {
      bigbunny=clone_object("/players/mizan/mines/beasties/L01/bigbunny.c");
      move_object(bigbunny, this_object());
   }

   if(arg) return;
   set_light(1);
   
   short_desc = HIY + "[1]" + NORM + " Dirt-Walled Hovel of the Big Bunny";
   long_desc =
   "    Up to your knees in tennis-ball sized bunny poop, you realize that\n" +
   "  you're in what is a partially above-ground rabbit burrow. The section\n"+
   "  that appears to go deeper underground however is rendered unusable as\n"+
   "  it has become completely plugged in with trash and dirt.\n";
   
  items = ({

    "floor",
    "The floor is absolutely filled with rabbit shit. At least it's not moving.",

  });
  
  dest_dir = 
  ({
  });

  set_no_clean(1);
}

