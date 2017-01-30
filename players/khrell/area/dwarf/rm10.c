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
         "players/khrell/area/dwarf/rm5.c", "east",
         "players/khrell/area/dwarf/rm11.c", "up",
         });
   return 1; }      
