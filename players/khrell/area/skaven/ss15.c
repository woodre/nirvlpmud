#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"["+HIW+"Skryre"+NORM+"]");
   set_long(
"   This is the outside of the main holding for Clan Skryre.  The\n"+
"air here has a stronger electric feel to it.  The near-suffocating\n"+
"conditions here weigh heavily upon all who are present. A path to\n"+
"the west leads back towards the commons.\n");    
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell a strong aroma of burnt metal.\n");
   items = ({
         "path", "It definately goes west, back towards the commons"});
   dest_dir = ({
         "players/khrell/area/skaven/ss14.c", "west",
         "players/khrell/area/skaven/skavenskyrelair.c", "enter"});
   move_object(clone_object("/players/khrell/monster/skaven/clanrat.c"), this_object());
   return 1; }
