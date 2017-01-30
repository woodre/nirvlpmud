#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(YEL+"Khazad Naggrund"+NORM+" ("+HIK+"Main Hold"+NORM+")");
   set_long(
"  This is s rough yet carefully hewn hallway within the city-keep.\n"+
"Intricate carvings along the walls depict things in the hold long\n"+
"before the scars and horrors of war changed it forever.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "carvings", "They show what life was once like in this hold.",
         "walls", "They are high enough to keep one from hitting their head on the ceiling."});
   dest_dir = ({
         "players/khrell/closed/dwarf/rm2.c", "east",
         "players/khrell/closed/dwarf/rm7.c", "north",
         "players/khrell/closed/dwarf/rm4.c", "west"});
   return 1; }





