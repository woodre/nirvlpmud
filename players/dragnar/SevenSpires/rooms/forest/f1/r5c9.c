inherit "/room/room.c";

#define MAPDM "/players/dragnar/SevenSpires/daemons/mapDM"

string room_name;

reset(arg) {
  if(arg) return;
  set_light(1);
  set_short("The Forest of Fear");
room_name = "r5c9";
set_long(MAPDM->get_map( basename( this_object() )));
dest_dir=({
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r4c9","north",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r6c9","south",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r5c8","west",
	 "/players/dragnar/SevenSpires/rooms/forest/f1/r5c10","east",
}); 
}
