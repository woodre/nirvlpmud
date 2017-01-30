#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+HIK+" - Eshin"+NORM);
   set_long(
"   This is the main chamber for Clan Eshin's local master, Skritt.\n"+
"Its sparsely decorated, with only a humble straw mat on the floor\n"+ 
"and a crude desk.\n");   
   set_light(-1);
   add_property("no_teleport");
   add_property("fight_area");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "mat", "More or less straw stuffed into a burlap mattress cover",
         "straw", "Its dried grass",
         "floor", "It is covered by a straw mat",
         "desk", "A rotted piece of wood supported upon uneven stones"});
   dest_dir = ({
         "players/khrell/area/skaven/skaveneshinarena.c", "exit"});
   move_object(clone_object("/players/khrell/monster/skaven/master_skritt.c"), this_object());
   return 1; }
