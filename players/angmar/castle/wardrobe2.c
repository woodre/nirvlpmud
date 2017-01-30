#pragma strong_types

inherit "room/room";

status door_is_open;

void
reset(status arg) {
  if(arg)
    return;
  set_light(1);
  short_desc = "Inside a wardrobe";
  long_desc =
"You are inside a wardrobe. You feel magic foces waiting to be released...\n";
  dest_dir = ({
    "players/angmar/fairyland/road1", "out"
  });
  items = ({
    "door", "It is closed"
  });
  set_light(1);
  door_is_open=0;
}

int query_door() { return !door_is_open; }

void
init() {
  ::init();
  add_action("open_door", "open");
  add_action("close_door", "close");
  add_action("out", "out");
}

void
move_to_other() {
  object ob, next_ob;
  ob = first_inventory(this_object());
  while(ob) {
    next_ob=next_inventory(ob);
    move_object(ob,"players/angmar/castle/wardrobe1");
    tell_object(ob,"You feel weightless for a moment.\n");
    ob=next_ob;
  }
}

status
out() {
  if (!door_is_open) {
    write("The door is closed.\n");
    return 1;
  }
  this_player()->move_player("out#players/angmar/fairyland/road1");
  return 1;
}

status
open_door(string str) {
  if (str != "door")
    return 0;
  if(door_is_open) {
    write("It is already open!\n");
    return 1;
  }
  door_is_open = 1;
  remove_item("door");
  add_item("door", "It is open");
  "players/angmar/fairyland/road1"->remove_item("wardrobe");
  "players/angmar/fairyland/road1"->add_item("wardrobe", "It is open");
  write("You open the door.\n");
  say(this_player()->query_name()+" opened the door.\n");
  return 1;
}

status
close_door(string str) {
  if(str != "door")
    return 0;
  if(!door_is_open) {
    write("It is already closed!\n");
    return 1;
  }
  remove_item("door");
  add_item("door", "It is closed");
  "players/angmar/fairyland/road1"->remove_item("wardrobe");
  "players/angmar/fairyland/road1"->add_item("wardrobe", "It is closed");
  door_is_open=0;
  write("You close the door.\n");
  say(this_player()->query_name()+" closed the door.\n");
  move_to_other();
  return 1;
}
