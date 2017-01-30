#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+HIY+"Commons"+NORM+"]");
   set_long(
"   This area is well lit and nearly spotless.  A sense of peace\n"+
"fills those that are here.\n"); 
   set_light(1);
   add_property("no_fight");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   dest_dir = ({
         "players/khrell/area/skaven/ss6.c", "east"});
   return 1; }
