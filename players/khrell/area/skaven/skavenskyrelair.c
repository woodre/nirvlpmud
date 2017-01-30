#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"["+HIW+"Skryre"+NORM+"]");
   set_long(
"   This is the main floor to the spiraling tower labratories of the\n"+
"skaven Clan Skryre.   These half mad arcane engineers build various\n"+
"devices, both of war and for their society.\n");   
   set_light(-1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "item", "NO/N"});
   dest_dir = ({
         "players/khrell/area/skaven/ss15.c", "leave",
         "players/khrell/area/skaven/skavenskyrelab1.c", "up"});
   move_object(clone_object("/players/khrell/monster/skaven/warleng.c"), this_object());
   return 1; }
