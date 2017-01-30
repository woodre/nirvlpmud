inherit "/room/room";
int closed, locked;
reset(arg) {
  if(arg) return;
  closed=1;
  locked=1;
  short_desc = "Right room";
  long_desc = "Right room...\"unlock\" or \"lock\" to lock/unlock the door\n"+
  "\"open\" or \"close\" to open/close the door\nexit is west.\n";
  set_light(1);
}
query_closed() { return closed; }

init() {
  add_action("west","west",1);
  add_action("lock","lock");
  add_action("unlock","unlock");
  add_action("open","open");
  add_action("close","close");
}

west() {
  if(closed) {
    write("The door is closed.\n");
    return 1;
  }
  this_player()->move_player("west#/players/grimm/ldoor");
  return 1;
}

lock() {
  if(locked) {
    write("The door is already locked.\n");
    return 1;
  }
  if(!closed) {
   write("You cannot lock an open door.\n");
   return 1;
  }
  locked=1;
  write("The door is locked.\n");
  return 1;
}

unlock() {
  if(!locked) {
    write("The door is not locked.\n");
    return 1;
  }
  locked=0;
  write("The door is unlocked.\n");
  return 1;
}

open() {
  if(locked) {
    write("The door is locked.\n");
    return 1;
  }
  if(!closed) {
    write("The door is already open.\n");
    return 1;
  }
  closed=0;
  write("The door is now open.\n");
  return 1;
}

close() {
  if(closed) {
    write("The door is already closed.\n");
    return 1;
  }
  closed=1;
  write("You close the door.\n");
  return 1;
}
