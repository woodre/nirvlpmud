#pragma strong_types

inherit "room/room";

#define LOCKED 0
#define CLOSED 1
#define OPEN 2

int door;
object da_thing;

void
reset(status arg) {
  "players/angmar/fairyland/inn"->reset(0);
  door = LOCKED;
  if (arg)
    return;
  set_light(1);
  set_light(1);
  short_desc = "Misty Mountain";
  long_desc = 
"You are climbing Misty Mountain.  There is a door set into\n" +
"the rock before you.\n";
  dest_dir = ({
    "players/angmar/fairyland/mountain_top", "up",
    "players/angmar/fairyland/mountain_foot", "down",
    "players/angmar/fairyland/rock_ledge", "east",
    "players/angmar/fairyland/tunnel", "north",
  });
  items = ({
    "misty mountain", "Misty Mountain still looms over you",
    "mountain", "Misty Mountain still looms over you",
    "door", "The door is closed"
  });
}

void
init(){
  room::init();
  add_action("try_north", "north");
  add_action("open", "open");
  add_action("unlock", "unlock");
  add_action("close", "close");
  add_action("lock", "lock");
}

status
lock(string str) {
  if (str != "door" && str != "door with key")
    return 0;
  if (door == LOCKED)
    write("The door is already locked.\n");
  else if (door == OPEN)
    write("The door is open.\n");
  else {
    da_thing = present ("key", this_player());
    if (da_thing) {
      if ((string)da_thing->query_code() == "auxd") {
        write("You lock the door.\n");
        say(this_player()->query_name()+ " locks the door.\n");
        door == LOCKED;
      }
      else
        write("You don't seem to have the right key.\n");
    }
    else
      write("You don't have a key!\n");
  }
  return 1;
}

status
close(string str) {
  if (str != "door")
    return 0;
  if (door != OPEN) 
    write("The door is already closed!\n");
  else {
    write("You close the door\n");
    remove_item("door");
    add_item("door", "The door is closed");
    "players/angmar/fairyland/tunnel"->remove_item("door");
    "players/angmar/fairyland/tunnel"->add_item("door","The door is closed");
    say(this_player()->query_name()+ " closes the door.\n");
    door = CLOSED;
  }
  return 1;
}

status
try_north() {
  if (door == LOCKED) {
    write("The door is locked!\n");
    return 1;
  }
  if (door == CLOSED) {
    write("The door is closed.\n");
    return 1;
  }
  return 0;
}

status
open(string str) {
  if (str != "door")
    return 0;
  if (door == LOCKED) {
    write("The door is locked.\n");
    return 1;
  }
  else {
    write("You open the door.\n");
    remove_item("door");
    add_item("door", "The door is open");
    "players/angmar/fairyland/tunnel"->remove_item("door");
    "players/angmar/fairyland/tunnel"->add_item("door","The door is open");    
    say(this_player()->query_name()+ " opens the door.\n");
    door = OPEN;
    return 1;
  }
}

status
unlock(string str) {
  if (str != "door" && str != "door with key")
    return 0;
  if (door == OPEN) 
    write("The door was already open!\n");
  else if (door == CLOSED)
    write("The door is already unlocked.\n");
  else {
    da_thing = present("key", this_player());
    if (da_thing) {
      if ((string)da_thing->query_code() == "auxd") {
        if (present("key", this_player())) {
          door = CLOSED;
          write("You unlock the door.\n");
          say(this_player()->query_name()+ " unlocks the door.\n");
        }
      }
      else
        write("You don't seem to have the right key!\n");
    }
    else
      write("You don't have a key!\n");
  }
  return 1;
}

status
query_door() {
  return door;
}

status
set_door(int arg) {
  door = arg;
  return arg;
}

status
auto_unlock() {
  door = OPEN;
  return 1;
}
