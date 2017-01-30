#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(GRN+"Fester Peak"+NORM+" ("+HIG+"Mines"+NORM+")");
   set_long(
"   These are the warpstone mines of Fester Peak.  Here, the slaves of\n"+
"the skaven toil away their miserable lives, which are always frantic,\n"+
"short and brutal.  Rough passages have been dug into the rock by the\n"+
"slaves in order to extract the precious warpstone that fuels nearly\n"+
"everything in skavendom.\n"); 
   set_light(-1);
   add_listen("main", "You hear faint chittering.\n");
   add_smell("main", "You smell nothing special.\n");
   items = ({
         "passage", "Unskilled hands or paws chisled the rock to make this",
         "passages", "Unskilled hands or paws chisled the rock to make these",
         "rock", "Solid stone with places where the warpstone has been extracted",
         "warpstone", "The solid stuff of chaos"});
   dest_dir = ({
         "players/khrell/area/skaven/skaventunnel5.c", "exit",
         "players/khrell/area/skaven/skavenwarpmine2.c", "north",
         "players/khrell/area/skaven/skavenwarpmine3.c", "south",
         "players/khrell/area/skaven/skavenwarpmine4.c", "east",
         "players/khrell/area/skaven/skavenwarppit1.c", "down",
         "players/khrell/area/skaven/skavenwarrens.c", "up"});
   move_object(clone_object("/players/khrell/monster/skaven/skavenslave.c"), this_object());
   return 1; }
