#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short("("+HIK+"Darkness"+NORM+")");
   set_long(
"   There is no possible way to light this section of the tunnel. Any\n"+
"attempts to light it seems to be instantly smothered by the opressing\n"+
"darkness, absorbing it utterly.  Adventurers can press on if they are\n"+
"brave or they can return to safer grounds.  It would require great \n"+
"bravery to press on and should not taken lightly by any sane creature.\n");
   set_light(-100);
   add_property("no_teleport");
   add_property("no_magic");
   add_property("no_follow");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "darkness", "Nothing but darkness not even light can penetrate it",
         "tunnel", "No ammount of light can seem to exist here in this tunnel"
         });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm13.c", "flee",
         "players/khrell/area/goblins/gobrm15.c", "ahead"
         });
   return 1; 
}
