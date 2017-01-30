inherit "room/room";

#define ROOMDM "/players/tristian/realms/supermax/obj/roomDM.c"

reset(arg) {
	  
  if(arg) return;
  
  short_desc = "Room1";
  set_light(1);
  dest_dir=({
    "/players/tristian/realms/supermax/rooms/room2","east",
  });
  long_desc=
"Test room1\n";
}

init() {
	::init();
  add_action("East","east");
  add_action("unlock","unlock");
  add_action("lock","lock");
}

East() {
  if( !ROOMDM->query_unlocked() ) {
    write("The door is locked\n");
    return 1;
  }
}

unlock() {
  ROOMDM->set_unlocked();
  write("You unlock the rooms.\n");
  return 1;
}

lock() {
  ROOMDM->set_locked();
  write("You lock the rooms.\n");
  return 1;
}
