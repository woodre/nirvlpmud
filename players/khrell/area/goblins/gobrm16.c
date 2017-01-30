#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIK+"The Lair"+NORM);
   set_long(
"  This gigantic cavern seems to be holding the unending darkness at\n"+
"bay, yet it contains something that is the lair of something very\n"+
"old and evil.  The remains of countless goblins lay scattered all\n"+
"over the floor.  A great mound of splintered and fragmented bones\n"+
"dominates the center of the room and you get the feeling it is some\n"+ 
"sort of nest.\n");
   set_light(1);
   add_property("fight_area");
   add_property("no_teleport");
   add_listen("main", "You hear nothing.\n");
   add_smell("main", "You smell nothing.\n");
   items = ({
         "cavern", "Large and vast reaching high into the air",
         "darkness", "There seems to be so little of it except from where you came",
         "lair", "The obivous signs of a beast's home, gnawed on bones and trash",
         "remains", "Shattered bones of many different creatures, mostly goblin",
         "goblins", "Dead for quite some time, no flesh remains",
         "bones", "Skeletal remains of many different goblins",
         "floor", "Aside from scattered bones there does seem to be stone beneath",
         "nest", "Piled bones create a rough bed for an occupant"
         });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm15.c", "escape"});
   move_object(clone_object("/players/khrell/monster/goblins/chaosspawn1.c"), this_object());
   move_object(clone_object("/players/khrell/monster/goblins/chaosspawn1.c"), this_object());
   return 1; }
