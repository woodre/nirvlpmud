#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+HIY+"Commons"+NORM+"]");
   set_long(
"   This is the center of the 'commons' area of Fester Peak.  Here\n"+
"a few stalagtites and stalagmites jut from the floor and ceiling in\n"+
"a ragged manner.  Normally, this area is ripe with merchants, but it\n"+
"has not seen any recent use.\n");
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "stalagtites", "They hang down from the ceiling like dark stone daggers",
         "stalagmites", "They stick up from the ground like black stone spikes"});
   dest_dir = ({
         "players/khrell/area/skaven/ss3.c", "south",
         "players/khrell/area/skaven/ss20.c", "west",
         "players/khrell/area/skaven/ss12.c", "north",
         "players/khrell/area/skaven/ss11.c", "east"});
   return 1; }
