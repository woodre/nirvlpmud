#include "/players/khrell/define.h"
#include <ansi.h>
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   
   set_short(HIG+"Goblin Caves "+NORM+"("+HIK+"Warped Chambers"+NORM+")");
   set_long(
"   Words can't quite describe the state of this disgusting chamber.\n"+
"Here once again is demonstrated the true nature of chaos towards\n"+
"things of order.  Corpses of countless goblins cover the walls and\n"+
"sick and twisted parody of building materials.  A mix of bodies of\n"+
"dead and nearly dead goblins form a tortured sculpture of a gruesome\n"+
"throne that literally writhes in the center of this madness.\n");
           
   set_light(1);
   add_property("no_teleport");
   add_listen("main", "You hear the sounds of the damned and tormented.\n");
   add_smell("main", "You smell corruption.\n");
   items = ({
	         "corpses", "Many dead goblins lay here their bodies a permanent part of the room",
	         "throne", "Shaped from goblins, some dead some alive, this seat churns the stomach",
	         "chamber", "A perversion of nature exist here with living things used as building material",
	         "goblins", "Dead and dieing goblins here are used as construction materials",
	         "walls", "Fused together countless goblins form what can only be called the walls",
	         "material", "Goblins used for building items",
	         "sculpture", "Meshed and melted goblins in some aberrant attempt at art",
	         "seat", "It turns your stomach to look at this seat"
            });
   dest_dir = ({
         "players/khrell/area/goblins/gobrm9.c", "south"
         });
   move_object(clone_object("/players/khrell/monster/goblins/gobshaman.c"), this_object());
   return 1; 
}
