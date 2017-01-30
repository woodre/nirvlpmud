#define rroom "/players/grimm/rdoor"
inherit "/room/room";
reset(arg) {
  if(arg) return;
  short_desc = "Left room";
  long_desc = "This is the left room.\nuse \"lock\" or \"unlock\" to lock/unlock the door.\n"+
  "and \"open\" or \"close\" to open/close the door.\nThe exit is east.\n";
  set_light(1);
}

init() {
  add_action("east","east");
  add_action("lock","lock");
  add_action("unlock","unlock");
  add_action("close","close");
  add_action("open","open");
}

east() {
  if(rroom->query_closed()) {
    write("The door is closed.\n");
    return 1;
  }
  this_player()->move_player("west#"+rroom);
  return 1;
}

lock() {
  rroom->lock();
  return 1;
}

unlock() {
  rroom->unlock();
  return 1;
}

close() {
  rroom->close();
  return 1;
}

open() {
  rroom->open();
  return 1;
}
