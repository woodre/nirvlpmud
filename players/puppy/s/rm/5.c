#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(""+CYN+"Smurfville playground"+NORM+"");
   set_long(
      "A fairly steep hill blocks everything from the east.  Walking\n"+
      "up the path, one could trip over the rocks laying on the\n"+
      "ground.  Some blocks that are stacked up in a pile lay off\n"+
      "off side of the path.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.");
   add_smell("main", "You smell nothing special.");
   items = ({
         "hill", "A steep hill",
         "steep hill", "A sleep hill",
         "path", "A worn trail in the grass",
         "pile", "A small stack of blocks neatly stacked", 
         "grass", "Lush vegetation that the Smurflings roll around on",
         "blocks", "A small pile of blocks that have been neatly stacked",
         "bunch of rocks", "Some colorful marbles",
         "a bunch of rocks", "Some colorful marbles",
         "rocks", "Some colorful marbles",
         "ground", "Grass with a small trail flowing through it",
         "marbles", "Some colorful marbles",
         "bunch of marbles", "Some colorful marbles",
         "a bunch of marbles", "Some colorful marbles"});
   dest_dir = ({
         "/players/puppy/s/rm/6.c", "north",
         "/players/puppy/s/rm/4.c", "west"});
   move_object(clone_object("/players/puppy/s/mob/baby/baby.c"), this_object());
   move_object(clone_object("/players/puppy/s/mob/baby/sas.c"), this_object());
   return 1; }
