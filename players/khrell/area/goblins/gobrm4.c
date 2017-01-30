#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIG+"Goblin Caves"+NORM);
   set_long(
"This intersection shows recent use.  The pervasive smell of unwashed\n"+
"goblins is everywhere.  More crude timber beams support chisled and \n"+
"mined works.  Again sounds of movement are heard and far off sounds\n"+
"of childlike squeals and giggles seem odd in such a dangerous place.\n"+
"Here seems to be a common place for the goblins to gather, bicker or\n"+
"other nasty things.\n");
   set_light(-1);
   add_listen("main", "You hear childlike giggles and squeals\n");
   add_listen("giggles", "You hear childlike giggles\n");
   add_listen("squeals", "You hear high pitched squeals\n");
   add_smell("main", "You smell the unwashed stench of goblins\n");
   add_smell("goblins", "You smell the horrid stench of unwashed goblins\n");
   items = ({
         "beams", "Poorly cut from trees they seem to barely do their job",
         "intersection", "This appears to be a split in the tunnel forking west, east and south"
         });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm3", "south",
         "players/khrell/area/goblins/gobrm5", "east",
         "players/khrell/area/goblins/gobrm6", "west",
         });
   move_object(clone_object("/players/khrell/monster/goblins/gobmob.c"), this_object());
   move_object(clone_object("/players/khrell/monster/goblins/gobmob.c"), this_object());
   move_object(clone_object("/players/khrell/monster/goblins/gobmob.c"), this_object());
   move_object(clone_object("/players/khrell/monster/goblins/gobmob.c"), this_object());
   return 1; }
