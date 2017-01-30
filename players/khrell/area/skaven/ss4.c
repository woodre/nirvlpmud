#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" [Slums]");
   set_long(
"   This alley looks to be the secondary depository for the refuse\n"+
"that the skaven always make.  Every bit of trash, junk or waste\n"+
"has been dumped here, leaving only a small pathway through the\n"+
"rubble, leading east and west.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_follow");
   add_listen("main", "You hear the scrabbeling of claws.\n");
   add_smell("main", "You smell rotting junk.  YUCK!\n");
   items = ({
         "refuse", "Various pieces of every-day things",
         "alley", "It's more of a pathway through the rubble",
         "rubble", "It is trash, junk, and refuse",
         "trash", "Assorted pieces of castoff litter",
         "junk", "Broken and disused items",
         "pathway", "The junk here has been nicely trampled to make this"});
   dest_dir = ({
         "players/khrell/area/skaven/ss1.c", "west",
         "players/khrell/area/skaven/ss10.c", "east"});
   return 1; }
