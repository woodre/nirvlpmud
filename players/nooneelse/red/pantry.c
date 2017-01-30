/*
pantry.c
*/

inherit "room/room";

object door1, door2;

string str, door_msg;

int door_is_open;

init() {
  ::init();

  add_action("open",       "open");
  add_action("down",       "down");
  add_action("close_door", "close");
  add_action("sniff",      "sniff");
}
 
open(str) {
  if (!str || str != "door") return;
  write("You can't open the door.\n");
  return 1;
}

down() {
  if (!door_is_open) {
    write("Bonk!  You bump your nose against the wall.\n"+
          "That was interesting.  Are you going to do it some more?\n");
    return 1;
  }
  say(this_player()->query_name()+
      " goes through the door and down the stairs.\n");
  tell_room("players/nooneelse/red/cellar1",this_player()->query_name()+
            " comes through the door and down the stairs.\n");
  move_object(this_player(), "players/nooneelse/red/cellar1");
  command("look", this_player());
  return 1;
}

close_door(str) {
  if (!str || str != "door") return;
  write("You can't close the door.\n");
  return 1;
}

sniff() {
  write("Yech!  That's a disgusting smell!\n");
  command("puke", this_player());
  return 1;
}
 
reset(arg) {
  if (arg) return;

  set_light(0);
  no_castle_flag=1;
  short_desc = "pantry";
  long_desc =
    "This hall contains large stocks of food.  Upon closer examination,\n"+
    "you see that all of it has succumed to rot and is completely useless.\n";
  items =
     ({
       "shelves", "Wooden shelves containing rotten foods.",
       "shelfs", "Wooden shelves containing rotten foods.",
       "shelf", "Wooden shelves containing rotten foods.",
       "food", "Oh gross!  It's all moldy, green and squishy.",
       "foods", "Oh gross!  It's all moldy, green and squishy.",
       "door", "It is a heavy, well-crafted stone door.",
       "stairs", "The wood looks worn and dry, but they look sturdy.",
     });
  dest_dir =
     ({
       "players/nooneelse/red/kitchen", "west",
     });
  door_is_open=0;
  door_msg="The door behind the shelves is closed.\n";
  return;
}

open_the_door(str) {
  say(
   "With a soft click, the door swings open, revealing stairs leading down.\n");
  door_msg=
    "The door behind the shelves stands open, revealing stairs leading down.\n";
  door_is_open=1;
}

query_door() { return door_is_open; }

long() {
  if (door_is_open) {
    write(long_desc);
    write(door_msg);
    write("    There are two obvious exits: west and down\n");
  }
  else {
    write(long_desc);
    write("    There is one obvious exit: west\n");
  }
}

id(str) {
  if (str=="door") {
    if (door_is_open){
      write(door_msg);
      return 1;
    }
  }
  if (str=="stairs" && door_is_open) return 1;
  return (str=="shelves" ||
          str=="shelfs" ||
          str=="shelf" ||
          str=="food" ||
          str=="foods");
}
