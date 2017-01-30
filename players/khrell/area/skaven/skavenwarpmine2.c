#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"("+HIG+"Mines"+NORM+")");
   set_long(
"   This is another section of the mines, where a great many slaves\n"+
"toil away their short lives in brutality.  This appears to be a \n"+
"recient dig as the workings here are fresh and undisturbed from\n"+
"time and elements.\n");
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "workings", "Dug mineworks from the extraction of warpstone",
         "mines", "The places were materials are dug from the rock",
         "mine", "A place where material is dug from the rock",
         "dig", "The crude workings of a mine"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenwarpmine1.c", "south"});
   move_object(clone_object("/players/khrell/monster/skaven/skavenslave.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/skavenslave.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/skavenslave.c"), this_object());
   return 1; }
