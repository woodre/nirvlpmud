#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(""+BLU+"Smurfette's living room"+NORM+"");
   set_long(
      "This brightly colored room is the handywork of Smurfette.\n"+
      "The pictures hanging against the side of the hut show that\n"+
      "almost everyone in Smurfville has been invited over at one\n"+
      "time or another.  The staircase on the opposite side of the\n"+
      "hut leads up to the living quarters and away from this place.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "pictures", "Pictures of the Smurfs",
         "room", "The inside of Smurfette's hut",
         "side of the hut", "The outer wall of this mushroom",
         "hut", "The inside of the mushroom you are in",
         "staircase", "The walkway up to Smurfette's bedroom"});
   dest_dir = ({
         "/players/puppy/s/rm/16.c", "up",
         "/players/puppy/s/rm/12.c", "out"});
   move_object(clone_object("/players/puppy/s/mob/smurfette.c"), this_object());
   move_object(clone_object("/players/puppy/s/eq/block.c"), this_object());
   return 1; }
