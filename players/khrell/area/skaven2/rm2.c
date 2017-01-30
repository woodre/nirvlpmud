#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak "+NORM+"["+MAG+"Moulder"+NORM+"]");
   set_long(
"  These would appear to be quarters for guests of Clan Moulder,\n"+
"but any sort of comforts any sane or normal person would consider\n"+
"having do not exist in this dank, smelly room.\n");
   set_light(0);
   add_property("fight_area");
   add_property("no_teleport");
   add_property("no_follow);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell all sorts of disgusting things.\n");
   dest_dir = ({"players/khrell/area/skaven2/rm1.c", "east"});
   