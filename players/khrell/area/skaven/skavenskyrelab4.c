#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"["+HIW+"Skryre"+NORM+"]");
   set_long(
"   This is the uppermost room of Clan Skryre's massive tower.\n"+
"And here is ther personal lair of the mighty Master Engineer \n"+
"Warlock Skrulkt.  Here he devises his mad inventions to further\n"+
"his own power.\n");   
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "item", "NO/N"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenskyrelab3.c", "down"});
   move_object(clone_object("/players/khrell/monster/skaven/skrulkt.c"), this_object());
   return 1; }
