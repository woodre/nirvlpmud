#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIG+"Goblin Caves"+NORM+"("+GRN+"Throne Room"+NORM+")");
   set_long(
"Goblins have obivously been bullied into making this room as respectful\n"+
"as possible for their big boss.  Though the words respectful and goblin\n"+
"never go together well.  Junk and refuse litter the floor and a dirty,\n"+
"soiled carpet lays crumpled before the 'throne'.\n");
   set_light(1);
   add_listen("main", "You hear nothing special\n");
   add_smell("main", "You smell foul unwashed bodies of goblins\n");
   items = ({
	    "junk", "What do you expect to see here? It's junk!",
	    "refuse", "Assorted and random bits and pieces of used junk",
	    "carpet", "It's covered in countless stains and other things best left undiscovered",
	    "throne", "More of a heaped pile of rocks then an actual throne",
         });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm11.c", "down",
         "players/khrell/area/underways/undermdh1.c", "enter"});
   move_object(clone_object("/players/khrell/monster/goblins/gobboss.c"), this_object());
   return 1;
   }