#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+HIR+"Council"+NORM+"]");
   set_long(
"   This run down area shows the careful attention of the skaven here.\n"+
"Moss covered flagstones give the faded illusion that, at one time, this\n"+
"may have been well maintained and kept.  Now nothing more then a rotting\n"+
"ruin.  The paws of the skaven are quite clear here as anything of real\n"+
"value has been stripped clean, or defiled in some horrific manner. To\n"+
"the north, the great spire of the temple of the Horned Rat looms high\n"+
"above, drowning everything in its ominous shadow.\n");
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell the stink of the skaven.\n");
   items = ({
         "moss", "It's just about everywhere here",
         "flagstones", "It was once a proud walkway for nobles, now just a ruin",
         "spire", "It looms high above your head",
         "temple", "The most unholy of places in this city",
         "shadow", "It covers the city in his gloom"});
   dest_dir = ({
         "players/khrell/area/skaven/ss18.c", "south",
         "players/khrell/area/skaven/skavenhallway1.c", "west",
         "players/khrell/area/skaven/skavenhallway2.c", "east",
         "players/khrell/area/skaven/skavenhallway3.c", "north"});
   move_object(clone_object("/players/khrell/monster/skaven/clanrat.c"), this_object());
   return 1; }
