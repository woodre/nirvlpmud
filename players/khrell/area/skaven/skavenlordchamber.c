#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+"["+RED+"Warlord"+NORM+"]");
   set_long(
"   This is the lowest part of 'Fester Peaks' Warlord's lair.  This\n"+
"is more of a gathering room than anything else.  Here is where the\n"+
"warlord would speak to any of his underlings.   It's Sparsely decorated\n"+
"with only a few unlit torches and a few crude straw beds.\n");
   set_light(-1);
   add_property("fight_area");
   add_property("no_teleport");
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "torches", "They aren't lit and look to be pure decoration",
         "straw", "It's poking through the sides of the beds",
         "beds", "Stuffed with straw and well stained"});
   dest_dir = ({
         "players/khrell/area/skaven/skavenhallway2.c", "out",
         "players/khrell/area/skaven/skavenlordwarren.c", "enter"});
   move_object(clone_object("/players/khrell/monster/skaven/stormvermin.c"), this_object());
   return 1; }
