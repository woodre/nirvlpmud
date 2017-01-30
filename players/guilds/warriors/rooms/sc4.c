#include "../define.h"

inherit ROOM;

reset(arg) {
if(!present("student_guard", this_object())){
   move_object(clone_object("/players/guilds/warriors/mobs/guard"), this_object());
   move_object(clone_object("/players/guilds/warriors/mobs/guard"), this_object());
   }
   if(arg) return;
   set_light(1);
   set_short("Hall of the Warriors");
   set_long(
   "This is the 2nd floor of the Warrior's Tower. A door stands to\n"+
   "the north and leads to the Master of the Towers Office. A stairway\n"+
   "leads down to the main hall.\n");
   add_property("NT");
   add_item("door",
   "A wooden door that leads to the master of the towers office");
   add_item("office",
   "The Master's Office where a promising student might enrollt into the school");
   add_item("stairway",
   "A stairway leading down to the main hall");   
   add_exit(ROOMS+"sc5","office");
   add_exit(ROOMS+"sc2","down");
   }

okay_follow() { return 1; }
query_no_fight() { return 1; }