inherit "/room/room.c";

#include <ansi.h>

#define MAPDM "/players/dragnar/SevenSpires/daemons/mapDM"

string room_name;

reset(arg) {
  if(arg) return;
  set_light(1);
  set_short("The "+HIBLK+"Black Spire"+NORM);
room_name = "r1c19";
set_long(MAPDM->get_map( basename( this_object() )));
dest_dir=({
	 "/players/dragnar/SevenSpires/rooms/citadel/s1/r1c18","west",
	 "/players/dragnar/SevenSpires/rooms/citadel/s1/r1c20","east",
}); 
}
