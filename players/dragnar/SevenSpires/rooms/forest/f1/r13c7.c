inherit "/room/room.c";

#define MAPDM "/players/dragnar/SevenSpires/daemons/mapDM"

string room_name;

reset(arg) {
  if(arg) return;
  set_light(1);
  set_short("The Forest of Fear");
room_name = "r13c7";
set_long(MAPDM->get_map( basename( this_object() )));
dest_dir=({
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r12c7","north",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r14c7","south",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r13c6","west",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r13c8","east",
}); 
}
