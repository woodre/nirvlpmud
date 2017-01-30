#include "ansi.h"
inherit "room/room";

reset(arg) {
	   if(!present("plumpy",this_object())) {
       move_object (clone_object("/players/martha/area/mobs/plumpy"), this_object());
   }
   
   if (arg) return;
   set_light(1);
   short_desc = HIM+"Gingerbread Plum Trees"+NORM;
   items = ({
	   "tree","A tall thornless tree",
	   "plum","A ripe, juicy gingerbread plum",
	   "limbs","Tree limbs with plums hanging from them",
	   "plums","Ripe, juicy gingerbread plums",
	   "pits","Rotted plum pits that have been spit on the ground",
	   "trees","Tall trees perfect for growing fruit on",
	   "leaves","A pile of trampled leaves",
	   "lair","A large area big enough for a troll",
	   "pile","A mound of rotted plums and cores",
	   "large hole","A hole large enough for a troll to squeeze through",
	   "hole","A hole large enough for a troll to squeeze through"});
	   
   long_desc =
"  Tall, thornless trees are scattered all around.  Ripe, juicy\n\
gingerbread plums adorn the limbs.  There is an enormous pile\n\
of half eaten plums and pits under one of the larger trees.\n\
It looks as though something has been pacing here, trampling\n\
the leaves.  One of the trees has a large hole in it, which\n\
looks to be a trolls lair.\n";
   dest_dir = ({"players/martha/area/rooms/rtrail", "north",
                     "players/martha/area/rooms/pforest", "east",
                     "players/martha/games", "back"});
}

