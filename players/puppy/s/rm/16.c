#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(""+BLU+"Smurfette's bedroom"+NORM+"");
   set_long(
      "From the top of the stairs one will notice that this bedroom is\n"+
      "decorated in mostly blue.  A bed with a blue comforter rests\n"+
      "against one wall with a window looking over the Smurflings\n"+
      "playground.  Above the window is a Smurflight that shows you the\n"+
      "stars at night.\n");
   set_light(1);
   add_listen("main", "You hear the Smurflings playing outside.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "bed", "A single bed with a blue comforter on it",
         "bedroom", "Smurfette's sleeping quarters",
         "room", "Smurfette's sleeping quarters",
         "playground", "The grassy area that the Smurflings use to gather and share toys",
         "blue comforter", "A blue down comforter stuffed with feathers",
         "comforter", "A blue down comforter stuffed with feathers",
         "Smurflight", "A opening in the ceiling that shows you the stars",
         "smurflight", "A opening in the ceiling that shows you the stars",
         "stairs", "The way to Smurfettes place",
         "stars", "The Smurflight is closed right now",
         "wall", "The wall of the hut",
         "window", "A window overlooking the Smurflings"});
   dest_dir = ({
         "/players/puppy/s/rm/14.c", "down"});
   move_object(clone_object("/players/puppy/s/mob/baby/baby.c"), this_object());
   move_object(clone_object("/players/puppy/s/eq/block.c"), this_object());
   return 1; }
