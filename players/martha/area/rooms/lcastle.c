#include "ansi.h"
inherit "room/room";

reset (arg) {
	if(!present("lord",this_object())) {
		move_object (clone_object("/players/martha/area/mobs/lord"), this_object());
	}

	if (arg) return;
	set_light(1);
	short_desc = HIB+"Licorice Castle"+NORM;
	items = ({
		"walls","The walls are made out of black licorice",
		"wall", "The wall is made out of black licorice",
		"bat", "The bat is made out of bitter chocolate",
		"bats", "The bats are small and bittersweet",
		"towers","Dark licorice towers loom",
		"cloud","Dark and dreary, the clouds hang low",
		"clouds","Dark and dreary, the clouds hang low"});
		
	long_desc = 
"   Dark licorice lines the outer walls of the Licorice Castle, where\n\
the evil Lord Licorice resides.  Bitter chocolate bats flutter around\n\
the castle towers.  Dark clouds hang over this part of Candy Land,\n\
making it gloomy and spooky.\n.";
	dest_dir = ({"players/martha/area/rooms/road", "southeast",
				 "players/martha/area/rooms/road2", "southwest"});
}
		