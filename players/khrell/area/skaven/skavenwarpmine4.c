#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"("+HIG+"Mines"+NORM+")");
   set_long(
"   This is an older part of the mine.  Although it is still in\n"+
"use, a small number of slaves work what little warpstone remains.\n");   
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "warpstone", "The raw stuff of solid chaos, it seems to draw in all light",
         "mine", "Worked by skaven for the express purpose of remove warpstone"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenwarpmine1.c", "west"});
   move_object(clone_object("/players/khrell/monster/skaven/skavenslave.c"), this_object());
   move_object(clone_object("/players/khrell/monster/skaven/skavenslave.c"), this_object());
   return 1; }
