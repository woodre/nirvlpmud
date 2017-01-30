#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIG+"Goblin Caves"+NORM+" (Warped Passage)");
   set_long(
"   The tunnel continues here, but the ground appears relatively\n"+
"solid and more sure footed. It would seem that this is the perfect\n"+
"place to rest and relax.  Though no place down here is truely safe  \n"+
"for anyone.\n");
   set_light(1);
   add_listen("main", "You hear nothing\n");
   add_smell("main", "You smell the faint stench of corruption\n");
   add_smell("stench", "You smell the stench of corruption\n");
   add_smell("corruption", "You smell the disgusting stench of the corrupt\n");
   items = ({
	         "tunnel", "A rough hewn dig done by goblin hands",
	         "ground", "Oddly it seems to be smooth and not rough at all",
         });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm8.c", "south",
         "players/khrell/area/goblins/gobrm10.c", "north"
         });
   move_object(clone_object("/players/khrell/monster/goblins/gobmob2.c"), this_object());
   return 1; }
