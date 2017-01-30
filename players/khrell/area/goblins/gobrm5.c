#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIG+"Goblin Caves"+NORM+" (Snotling pens)");
   set_long(
"A rough hewn pit dominates what could vaguely be called a room. Many\n"+
"types of small fungi grow about in the corners and the edges. A great\n"+
"many creatures have made use of this room in the past. Fresh footprints \n"+
"both large and small litter the floor.\n");
            
   set_light(1);
   add_listen("main", "You hear nothing special\n");
   add_smell("main", "You smell mold, mildew, and fecal matter\n");
   items=({ "pit", "The communal drops are filled with goblinoid waste",
            "fungi", "Tall pointed mushroom caps lay all about",
            "corners", "They appear to be covered in the fungoid mushrooms",
            "edges", "Mushrooms of varied sizes grow here",
            "footprints", "They seem to be of common goblin and the lesser snotling type",
            "floor", "The floor is covered in footprints"
      });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm4", "west",
         "players/khrell/area/goblins/gobrm11.c", "in"});
   move_object(clone_object("/players/khrell/monster/goblins/gobminder.c"), this_object());
   move_object(clone_object("/players/khrell/monster/goblins/snotling.c"), this_object());
   move_object(clone_object("/players/khrell/monster/goblins/snotling.c"), this_object());
   move_object(clone_object("/players/khrell/monster/goblins/snotling.c"), this_object());
   move_object(clone_object("/players/khrell/monster/goblins/snotling.c"), this_object());
   return 1; 
}
