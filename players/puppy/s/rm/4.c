#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(""+CYN+"Smurfville playground"+NORM+"");
   set_long(
      "The path opens up into a small field which the Smurflings\n"+
      "use as a place to gather.  There is no set of standard\n"+
      "equipment here for them to play on except for some tree\n"+
      "branches and rocks.  A swing tied with some thorny vines\n"+
      "hangs down from an oak tree.\n");
   set_light(1);
   add_listen("main", "The laughter of the Smurflings makes everyone smile.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "path", "A worn patch of grass through the playground",
         "small field", "A place where the Smurflings come to have fun",
         "field", "A place where the Smurflings come to have fun",
         "rocks", "Some small boulders that are staggered throughout the field",
         "swing", "Pieces of wood and vines tied together that the Smurflings have fun with",
         "thorny vines", "Green vines used to secure the swing to the oak tree",
         "vines", "Green vines used to secure the swing to the oak tree",
         "oak tree", "A tree that the Smurflings enjoy climbing",
         "oak", "A tree that the Smurflings enjoy climbing",
         "tree", "A tree that the Smurflings enjoy climbing",
         "tree branches", "Some rather large pieces of wood that Pup Smurf has fetched for the Smurflings",
         "branches", "Some rather large pieces of wood that Pup Smurf has fetched for the Smurflings",
         "grass", "Thick blades of grass"});
   dest_dir = ({
         "/players/puppy/s/rm/7.c", "north",
         "/players/puppy/s/rm/5.c", "east",
         "/players/puppy/s/rm/3.c", "southwest"});
   move_object(clone_object("/players/puppy/s/mob/baby/nat.c"), this_object());
   move_object(clone_object("/players/puppy/s/mob/baby/pup.c"), this_object());
}
