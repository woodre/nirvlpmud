#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIG+"Goblin Caves"+NORM);
   set_long(
"   It appears there was once some grand statue in this room but\n"+
"as usual the goblins have defiled or 'kuztumiz'd' it to fit their \n"+
"destructive moods.  Detestable graffiti and crude drawings now \n"+
"cover the walls.  Though what original purpose it once held has\n"+
"long since been forgotten, it now seems to serve as living space\n"+
"for some of the larger goblins.\n");
   set_light(1);
   add_listen("main", "You hear nothing special.\n");
   add_smell("main", "You smell nothing special.\n");
   dest_dir = ({
                "players/khrell/area/goblins/gobrm5.c", "out",
                "players/khrell/area/goblins/gobrm12.c", "up"
         });
   items = ({
	         "graffiti", "Poorly drawn and impossible to read",
	         "drawings", "Depictions of goblinoid prowess in combat",
	         "walls", "They are covered in crude drawings and graffiti",
	         "statue", "It appears to have once been of dwarven make, but now it's badly damaged"
         });
   move_object(clone_object("/players/khrell/monster/goblins/gobmob3.c"), this_object());
   move_object(clone_object("/players/khrell/monster/goblins/gobmob3.c"), this_object());
   return 1; 
}
