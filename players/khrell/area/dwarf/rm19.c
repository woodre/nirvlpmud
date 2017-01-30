#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Khazad Naggrund"+NORM+"("+HIK+"Main Hold"+NORM+")");
   set_long(
"This is the description.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "item", "NO/N"});
   dest_dir = ({
	     "players/khrell/area/dwarf/rm22.c", "north",
         "players/khrell/area/dwarf/rm18.c", "south",
         "players/khrell/area/dwarf/rm21.c", "west",
         "players/khrell/area/dwarf/rm20.c", "east",
         });
   return 1; }
