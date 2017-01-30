#define tp this_player()

#define tpn this_player()->query_name()

#define tpp this_player()->query_possessive()

inherit "room/room";

#include "/players/jaraxle/ansi.h"

object guard;

object civ;



reset(arg) {

if(!present("cont_lizardman", this_object())){

civ = clone_object("/players/jaraxle/cont/ltown/mobs/lcivilian.c");

	move_object(civ, this_object());

	}

if(!present("cont_lizardguard", this_object())){

guard = clone_object("/players/jaraxle/cont/ltown/mobs/lguard.c");

	move_object(guard, this_object());

}

  if(arg) return;

set_light(1);



short_desc = "Third Earth ["+HIG+"Terk'ula"+NORM+"]";

long_desc =

"   You have reached the end of the village. Before you is\n"+

"the wooden fence, and behind you a road leads south through\n"+

"the village. To the east is a dingy alley, and to the west\n"+

"is a rundown hut.\n";

items = ({

  "road",

  "A dirt road that leads through the center of town",

  "fence",

  "A tall wooden wall that defends the village from attacks",

  "alley",

  "A dirty trash-strewn alley. It does not look safe",

  "hut",

  "A filthy rundown hut that looks to be uninhabited. A\n"+

  "large filthy pool of water flows from the back of it",

});



dest_dir = ({

  "/players/jaraxle/cont/ltown/rooms/l4.c","east",

  "/players/jaraxle/cont/ltown/rooms/hut4.c", "west",

  "/players/jaraxle/cont/ltown/rooms/l3.c", "south",

});



}



