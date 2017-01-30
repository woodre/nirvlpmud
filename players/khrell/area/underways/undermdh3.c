#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
 This intersection is in total disarray. The smoothly crafted stone walls\n\
are chipped and cracked.  A fine layer of dust has settled over the debris\n\
that litters the ground.  Strangely, the dust appears to have been disturbed\n\
recently by something very large. \n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "walls", "Apparently at one time they were smooth, now they are chipped and cracked",
         "debris", "Shattered pieces of the walls and support pillars litter the ground",
         "dust", "It makes you want to sneeze, as there is so much of it",
         "ground", "It is covered in a fine layer of dust",
         "intersection", "A place where two hallways meet",
         "wall", "Apparently at one time it was smooth, now it is chipped and cracked",
         "layer", "A slight covering of dust",
         "pillars", "Supports carved from stone",
         "pillar", "A support carved from stone",
         "chip", "A broken small piece of stone",
         "chipped", "Damaged from missed weapon swings",
         "cracks", "Created from a seismic disturbance",
         "crack", "One of many that have marred this once flawless wall"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh1.c", "north",
         "players/khrell/area/underways/undermdh5.c", "west",
         "players/khrell/area/underways/undermdh4.c", "east",
         "players/khrell/area/underways/undermdh6.c", "south"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
