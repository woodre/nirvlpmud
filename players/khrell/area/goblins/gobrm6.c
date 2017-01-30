#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIG+"Goblin Caves"+NORM);
   set_long(
"   This tunnel continues to show the complete lack of skill of the\n"+
"goblinoids.  Rough hewn timbers and other unidentifable materials\n"+
"support the ramshackle roof above.  The occasional glowing fungus\n"+
"provides an odd lumination here.\n");
            
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
	         "timbers", "More prime examples of shoddy goblinoid workmanship.",
	         "fungus", "Glowling slightly they provide a fair ammount of light",
	         "tunnel", "Shoddy skills and lack of proper knowledge give it a condemed look",
	         "roof", "Moldy and half rotten timbers complete this typical goblin work of contruction",
	         "materials", "You see rusted iron nails, splintered wood and dulled picks"
            }); 
   dest_dir = ({
         "players/khrell/area/goblins/gobrm4.c", "east",
         "players/khrell/area/goblins/gobrm7.c", "north"
         });
}