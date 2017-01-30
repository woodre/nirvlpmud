inherit "/room/room.c";

#include <ansi.h>

#define MAPDM "/players/dragnar/SevenSpires/daemons/mapDM"

string room_name;

reset(arg) {
  if(arg) return;
  set_light(1);
  set_short("The "+HIBLK+"Black Spire"+NORM);
room_name = "r8c18";
set_long(MAPDM->get_map( basename( this_object() )));
dest_dir=({
	 "/players/dragnar/SevenSpires/rooms/citadel/s1/r7c18","north",
	 "/players/dragnar/SevenSpires/rooms/citadel/s1/r9c18","south",
	 "/players/dragnar/SevenSpires/rooms/citadel/s1/r8c17","west",
	 "/players/dragnar/SevenSpires/rooms/citadel/s1/r8c19","east",
}); 
}
