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
	     "players/khrell/closed/dwarf/rm27.c", "north",
	     "players/khrell/closed/dwarf/rm19.c", "south",
         "players/khrell/closed/dwarf/rm24.c", "west",
         "players/khrell/closed/dwarf/rm23.c", "east",
         });
   return 1; }