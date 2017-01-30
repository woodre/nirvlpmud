#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ["+YEL+"Pestilens"+NORM+"]");
   set_long(
"   The Clan Pestilens section is quite literally the most foul place\n"+
"in all of skavendom, and that is saying alot.  Noxious odors and fumes\n"+
"visibly float in the air. Diseased, bloated and putrified corpses\n"+
"cover the streets as flies buzz noisily about.\n");
   set_light(-1);
   add_listen("main", "You hear loud buzzing of countless flies.\n");
   add_smell("main", "You smell sickeningly sweet smell of decay.\n");
   items = ({
         "fumes", "The byproduct of the masses of diseased, decaying corpses",
         "flies", "Large swollen insects that seem to live off and in the corpses",
         "corpses", "They are in various stages of decay and all appear to have died in agony"});
   dest_dir = ({
         "players/khrell/area/skaven/ss13.c", "east",
         "players/khrell/area/skaven/ss17.c", "west"});
   return 1; }
