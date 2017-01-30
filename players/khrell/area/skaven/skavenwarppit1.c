#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"("+HIG+"Mines"+NORM+")");
   set_long(
"   This is where the skaven banish the badly mutated or those\n"+
"otherwise unfit for slave labor.  A thick layer of some sort of\n"+
"sludge covers the walls and floor, and drips constantly overhead.\n");   
   set_light(-1);
   add_property("no_magic");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "sludge", "A thick syrup-like substance that churns your stomach",
         "walls", "They are completely covered in the thick sludge",
         "wall", "It is covered in the thick sludge",
         "floor", "It's completely covered in the thick sludge",
         "ceiling", "Small cracks in it let the sludge drip through"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenwarpmine1.c", "up",
         "players/khrell/area/skaven/skavenwarppit2.c", "climb",
         "players/khrell/area/skaven/skavenwarppit3.c", "down"});
   move_object(clone_object("/players/khrell/monster/skaven/sludgespawn.c"), this_object());
   return 1; }
