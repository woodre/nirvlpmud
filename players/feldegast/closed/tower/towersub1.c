inherit "room/room";
  int locked;
reset(arg) {
  locked=1;
  if (arg) return;
  set_light(1);
  short_desc="The Tower's Basement";
  long_desc=
"     This is a small room at the bottom of a flight of marble\n"+
"stairs.  Guttering torches cast shadows across the walls.  To\n"+
"the north is an oak door leading into the dungeon.\n";
  items=({
  });
  dest_dir=({
    "/players/feldegast/closed/tower/dungeon","north",
    "/players/feldegast/closed/tower/tower0","up"
  });
}
init() {
  ::init();
  add_action("block","north");
  if(this_player()->query_real_name()=="feldegast")
    add_action("lock","lock");
}
set_lock(arg) {
  locked=arg;
}
lock() {
  if(locked) {
    locked=0;
    write("You unlock the door.\n");
  }
  else {
    locked=1;
    write("You lock the door.\n");
  } 
  return 1;
}
block() {
  if(locked) {
    write("The door is locked.\n");
    return 1;
  }
}
