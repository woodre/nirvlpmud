#pragma strong_types

inherit "room/room";

void
reset(status arg) {
  if (arg)
    return;
  set_light(1);
  short_desc = "On a road in Fairyland";
  long_desc = 
"You are standing on a road in Fairyland.  The road\n" +
"continues to the north.  Above you floats a wardrobe,\n" +
"hovering in the same position.\n";
  dest_dir = ({
    "players/angmar/fairyland/road2", "north",
    "players/angmar/fairyland/edge1", "south",
  });
  items = ({
    "road",
    "The road has a magical quality to it.  This realm is different, somehow",
    "fairyland", "You can't possibly see all of it from here",
    "wardrobe", "It is closed"
  });
}

string realm() { return ("fairyland"); }

void
init() {
  room::init();
  add_action("open","open");
  add_action("close","close");
  add_action("enter","enter");
}

status
open(string str) {
  if (str != "door" && str != "wardrobe")
    return 0;
  remove_item("wardrobe");
  add_item("wardrobe", "It is open");
  "players/angmar/castle/wardrobe2"->open_door("door");
  return 1;
}

status
close(string str) {
  if(str != "door" && str != "wardrobe")
    return 0;
  remove_item("wardrobe");
  add_item("wardrobe", "It is closed");
  "players/angmar/castle/wardrobe2"->close_door("door");
  return 1;
}

status
enter(string str) {
  if (str != "door" && str != "wardrobe")
    return 0;
  if ("players/angmar/castle/wardrobe2"->query_door()) {
    write("The door is closed.\n");
    return 1;
  }
  this_player()->move_player(
    "into the wardrobe#players/angmar/castle/wardrobe2");
  return 1;
}
