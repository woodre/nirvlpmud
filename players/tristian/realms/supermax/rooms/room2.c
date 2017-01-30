inherit "room/room";

#define ROOMDM "/players/tristian/realms/supermax/obj/roomDM.c"

reset(arg) {
	  
  if(arg) return;
  
  short_desc = "Room2";
  set_light(1);
  dest_dir=({
    "/players/tristian/realms/supermax/rooms/room1","west",
  });
  long_desc=
"Test room2\n";
}

init() {
	::init();
  add_action("West","west");
}

West() {
  if( !ROOMDM->query_unlocked() ) {
    write("The door is locked\n");
    return 1;
  }
}
