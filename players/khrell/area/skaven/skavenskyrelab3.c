#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"["+HIW+"Skryre"+NORM+"]");
   set_long(
"   This is where a great many of the Warlock Engineers of Clan\n"+
"Skryre spend their off hours.  Various shelves, weapon racks, \n"+
"and crates are aligned with large billowing straw mattresssess\n"+
"where the skaven sleep or rest for short periods.\n");
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "shelves", "Used for storing items",
         "weapon racks", "Commonly used for storing weapons, but is empty now",
         "crate", "A large wooden container used for storing items",
         "crates", "Large wooden containers used for storing items",
         "mattress", "Rough cloth stuffed with straw"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenskyrelab2.c", "down",
         "players/khrell/area/skaven/skavenskyrelab4.c", "up"});
   move_object(clone_object("/players/khrell/monster/skaven/warleng3.c"), this_object());
   return 1; }
