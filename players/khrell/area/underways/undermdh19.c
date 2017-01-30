#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Ruins of Khazad Naggrund"+NORM);
   set_long("\
This was the outermost gates to Khazad Naggrund.  Some mighty force has all\n\
but reduced the gates to fragments.  Beyond the gates expands a clearly mined\n\
area.  Far off to the south is a large cave in.\n");  
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "gates", "At one time they must have been well built, now just another sad ruin",
         "fragments", "Splintered and broken remains of the once proud mighty gates",
         "mined", "Clearly the works of dwarves, as it is percise and well supported",
         "gate", "At one time it was well built, now just another ruin",
         "ruin", "The remains of the mighty gates of Khazad Naggrund",
         "remains", "The result of siege work versus a mighty gate",
         "fragment", "The results of siege work against the gates",
         "rock", "Solid stone of the earth",
         "debris", "The shattered gates remains from the siege",
         "mined area", "Where once the dwarves once mined for gems and minerals",
         "area", "Where once the dwarves once mined for gems and minerals",
         "cave in", "A large pile of rock and other debris, perhaps in time it will be cleared away"});
   dest_dir = ({
         "players/khrell/area/underways/undermdh18.c", "north",
         "players/khrell/area/skaven/under1.c", "enter"});
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   move_object(clone_object("/players/khrell/monster/underways/golrnd.c"), this_object());
   return 1; }
