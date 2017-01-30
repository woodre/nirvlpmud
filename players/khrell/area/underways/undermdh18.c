#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
This was once a great gate-house, separating the inner and outer gates.\n\
Nothing of interest remains here, except telltale signs of a siege: blood\n\
splatter, splintered wood and the broken remains of combatants.\n");   
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "blood", "The dark greens and reds of both dwarves and goblins",
         "gate-house", "The area that once directed fraffic in and out of the hold",
         "gate", "To the north and south were once mighty gates",
         "shrapnel", "The shattered remains of two destroyed gates",
         "scraps", "Small pieces of bone",
         "shreds", "Small pieces of armor",
         "armor", "Now nothing more then piles of rust",
         "wood", "The shrapnel of two destroyed gates",
         "remains", "Scraps of bone, shreads of armor give you the idea of a battle waged here"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh15.c", "north",
         "players/khrell/area/underways/undermdh19.c", "south"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
