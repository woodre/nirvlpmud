inherit "/room/room.c";

#define MAPDM "/players/dragnar/SevenSpires/daemons/mapDM"

string room_name;

reset(arg) {
  if(arg) return;
  set_light(1);
  set_short("The Forest of Fear");
room_name = "r13c8";
set_long(MAPDM->get_map( basename( this_object() )));
dest_dir=({
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r12c8","north",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r14c8","south",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r13c7","west",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r13c9","east",
}); 
}
