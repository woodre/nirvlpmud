#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short("("+HIK+"Darkness"+NORM+")");
   set_long(
"   The darkness continues here.  The fact that no light can be used\n"+
"does little to settle the constant fear that you are in mortal danger.\n"+
"The gibbering madness has ceased yet you still feel danger up ahead.\n"+
"You can't tell how far you have actually walked or where you are.\n");
   set_light(-5);
   add_property("no_teleport");
   add_property("no_magic");
   add_listen("main", "You hear nothing.\n");
   add_smell("main", "You smell nothing.\n");
   items = ({
         "darkness", "An occasional etherial visage appears then quickly vanishes."});
   dest_dir = ({
         "players/khrell/area/goblins/gobrm14.c", "flee",
         "players/khrell/area/goblins/gobrm16.c", "ahead"
         });

   return 1; 
}
