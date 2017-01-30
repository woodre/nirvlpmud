#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" [Slums]");
   set_long(
"   The shadows cover everything here.  Only slight differences\n"+
"in the depth of their dark color give one any sense of direction\n"+
"here.  Darker regions to the north and south create the vague\n"+
"suggestion of exits to other parts of the slums.\n");
   set_light(-2);
   add_property("fight_area");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "shadows", "They fill the area and blanked you in a cold dread",
         "slums", "Barely visible from this point now, you wonder how far they go"});
   dest_dir = ({
         "players/khrell/area/skaven/ss5.c", "south",
         "players/khrell/area/skaven/ss8.c", "north"});
   return 1; }
