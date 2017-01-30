inherit "/room/room.c";

#define MAPDM "/players/dragnar/SevenSpires/daemons/mapDM"

string room_name;

reset(arg) {
  if(arg) return;
  set_light(1);
  set_short("The Forest of Fear");
room_name = "r2c11";
set_long(MAPDM->get_map( basename( this_object() )));
dest_dir=({
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r1c11","north",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r3c11","south",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r2c10","west",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r2c12","east",
}); 
}
