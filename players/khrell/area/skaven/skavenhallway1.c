#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+HIK+"Greyseer"+NORM+"]");
   set_long(
"   This is the bottom floor and main entry to the chambers of the\n"+
"local Greyseer.  It is simply decorated with nothing outlandish or\n"+
"impressive.  The only thing of note is a ladder that leads upward.\n");
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "ladder", "It's made from fused bones"});
   dest_dir = ({
         "players/khrell/area/skaven/ss19.c", "east",
         "players/khrell/area/skaven/skavengreyschamber.c", "up"});
   move_object(clone_object("/players/khrell/monster/skaven/clanrat.c"), this_object());
   return 1; }
