#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ("+CYN+"Underwarrens"+NORM+")");
   set_long(
"   This is the northwestern area of the vast, sprawling underwarrens.\n"+
"It is well-lit here with torches placed in sconces along the wall\n"+
"and a great many straw beds cover the floor.\n");
   set_light(1);
   add_property("no_fight");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "torches", "They sputter sporadically, casting odd shadows across the walls",
         "sconces", "Rusted metal fittings made to hold the torches",
         "beds", "Rough mattresses stuffed with straw",
         "straw", "Dried tall grass"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenwarrens.c", "southeast"});
   return 1; }
