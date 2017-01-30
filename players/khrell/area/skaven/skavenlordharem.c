#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"["+RED+"Warlord"+NORM+"]");
   set_long(
"   This is the warlord's private harem. Normally it would be filled\n"+
"with the docile skaven females, but it is empty now.  This is the\n"+
"innermost place for the warlord.  Various rusted chains hang from\n"+
"the wall, obviously the way one would keep the breeders from running\n"+
"off.\n");
   set_light(-1);
   add_property("no_teleport");
   add_property("fight_area");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "chains", "They look to hold creatures as prisoners",
         "wall", "A number of rusted chains hang from this"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenlordwarren.c", "out"});
   move_object(clone_object("/players/khrell/monster/skaven/warlord.c"), this_object());
   return 1; }
