#pragma strong_types

inherit "room/room";

#define LOCKED 0
#define CLOSED 1
#define OPEN 2

object da_thing;

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  set_light(1);
  short_desc = "A tunnel in the mountain";
  long_desc = 
"You are in a tunnel deep in the mountain.  You can see a red\n" +
"glow far away.  A sign on the door says: 'If the door is\n" +
"locked just knock.\n";
  dest_dir = ({
    "players/angmar/fairyland/mountain", "south",
    "players/angmar/fairyland/dragonroom", "north",
  });
  items = ({
    "door", "The door seems very strong",
    "glow", "The glow lies to the north, and pulsates rhythmically",
    "sign", "The sign reads:\n     If the door is locked, just knock",
  });
}

void
init() {
  room::init(); 
  add_action("try_south", "south");
  add_action("read", "read");
  add_action("open", "open");
  add_action("unlock", "unlock");
  add_action("close", "close");
  add_action("lock", "lock");
  add_action("knock", "knock");
}

status
try_south() {
  if ((int)"players/angmar/fairyland/mountain"->query_door() == LOCKED) {
    write("The door is locked!\n");
    return 1;
  }
  if ((int)"players/angmar/fairyland/mountain"->query_door() == CLOSED) {
    write("The door is closed.\n");
    return 1;
  }
  return 0;
}

status
lock(string str) {
  if (str != "door" && str != "door with key")
    return 0;
  if ((int)"players/angmar/fairyland/mountain"->query_door() == LOCKED)
    write("The door is already locked.\n");
  else if ((int)"players/angmar/fairyland/mountain"->query_door() == OPEN)
    write("The door is open.\n");
  else{
    da_thing = present("key", this_player());
    if (da_thing) {
      if ((string)da_thing->query_code() == "auxd") {
        write("You lock the door.\n");
        say(this_player()->query_name()+ " locks the door.\n");
        "players/angmar/fairyland/mountain"->set_door(LOCKED);
      }
      else
        write("You don't seem to have the right key.\n");
    }
  }
  return 1;
}

status
close(string str) {
  if (str != "door")
    return 0;
  if ((int)"players/angmar/fairyland/mountain"->query_door() != OPEN)
    write("The door is already closed!\n");
  else {
    write("You close the door.\n");
    remove_item("door");
    add_item("door", "The door is closed");
    "players/angmar/fairyland/mountain"->remove_item("door");
    "players/angmar/fairyland/mountain"->add_item("door","The door is closed");
    say(this_player()->query_name()+ " closes the door.\n");
    "players/angmar/fairyland/mountain"->set_door(CLOSED);
  }
  return 1;
}

status
open(string str) {
  if (str != "door")
    return 0;
  if ((int)"players/angmar/fairyland/mountain"->query_door() == LOCKED) {
    write("The door is locked.\n");
    return 1;
  }
  else {
    write("You open the door.\n");
    remove_item("door");
    add_item("door", "The door is closed");
    "players/angmar/fairyland/mountain"->remove_item("door");
    "players/angmar/fairyland/mountain"->add_item("door","The door is closed");
    say(this_player()->query_name()+ " opens the door.\n");
    "players/angmar/fairyland/mountain"->set_door(OPEN);
    return 1;
  }
}

status
unlock(string str) {
  if (str != "door" && str != "door with key")
    return 0;
  if ((int)"players/angmar/fairyland/mountain"->query_door() == OPEN)
    write("The door is already open.\n");
  else if ((int)"players/angmar/fairyland/mountain"->query_door() == CLOSED)
    write("The door is already unlocked.\n");
  else {
    da_thing = present("key", this_player());
    if (da_thing) {
      if ((string)da_thing->query_code() == "auxd") {
        if (present("key", this_player())) {
          "players/angmar/fairyland/mountain"->set_door(CLOSED);
          write("You unlock the door.\n");
          say(this_player()->query_name()+ " unlocks the door.\n");
        }
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
knock() {
  write("Ok.\n");
  say(this_player()->query_name() + " knocks on the door.\n");
  remove_item("door");
  add_item("door", "The door is closed");
  "players/angmar/fairyland/mountain"->remove_item("door");
  "players/angmar/fairyland/mountain"->add_item("door","The door is closed");
  "players/angmar/fairyland/mountain"->set_door(CLOSED);
  return 1;
}

status
read(string str) {
  if (!str)
    return 0;
  if (str != "sign")
    return 0;
  write("The sign reads:\n     If the door is locked, just knock.\n");
  say(this_player()->query_name() + " reads the sign.\n");
  return 1;
}
