inherit "/room/room.c";

#define MAPDM "/players/dragnar/SevenSpires/daemons/mapDM"

string room_name;

reset(arg) {
  if(arg) return;
  set_light(1);
  set_short("The Forest of Fear");
room_name = "r10c12";
set_long(MAPDM->get_map( basename( this_object() )));
dest_dir=({
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r9c12","north",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r10c13","east",
}); 
}
