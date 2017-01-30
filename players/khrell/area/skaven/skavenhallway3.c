#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+CYN+"Temple"+NORM+"]");
   set_long(
"   This is the grand stairway leading to the main temple doors.  At\n"+
"one time, these steps were of smoothed marble.  Now, just cracked and\n"+
"splintered stone, crudely placed for ease at ascending or descending.\n"+
"Ahead, the towering spire of the massive Temple of the Horned Rat looms,\n");
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "stairway", "They lead up to the temple doors",
         "steps", "Cracked and broken, comonly used to go up and down",
         "doors", "They are still a ways to the north",
         "temple", "The unholy place where the skaven worship",
         "marble", "It is nothing now more then shattered rock",
         "stone", "Poorly made and placed here to cover up holes",
         "spire", "It looms high above you"});
   dest_dir = ({
         "players/khrell/area/skaven/ss19.c", "south",
         "players/khrell/area/skaven/skavenhallway4.c", "north"});
   move_object(clone_object("/players/khrell/monster/skaven/clanrat.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/clanrat.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/stormvermin.c"), this_object());
   return 1; }
