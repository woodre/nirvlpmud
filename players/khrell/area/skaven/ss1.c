#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" [Slums]");
   set_long(
"   The aptly named slums leaves nothing to the imagination, an\n"+
"unkempt place where only the dregs of skaven society dwell or \n"+
"even traverse.  The stench of trash mingles with the musk of the\n"+
"skaven.  To the north is the better kept commons and council area,\n"+
"while to the east and west are more of the slums.\n"); 
   set_light(-1);
   add_property("fight_area");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell trash and the musk of the skaven.\n");
   items = ({
         "item", "NO/N"});
   dest_dir = ({
         "players/khrell/area/skaven/ss2.c", "west",
         "players/khrell/area/skaven/ss3.c", "north",
         "players/khrell/area/skaven/ss4.c", "east",
         "players/khrell/area/skaven/skavenwarrens.c", "down"});
   move_object(clone_object("/players/khrell/monster/skaven/clanrat.c"), this_object());
   return 1; }
