inherit "/room/room.c";

#define MAPDM "/players/dragnar/SevenSpires/daemons/mapDM"

string room_name;

reset(arg) {
  if(arg) return;
  set_light(1);
  set_short("The Forest of Fear");
room_name = "r5c5";
set_long(MAPDM->get_map( basename( this_object() )));
dest_dir=({
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r4c5","north",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r5c4","west",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r5c6","east",
}); 
}
