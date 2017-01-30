/*
 nautilus_deck.c - aft deck of the nautilus
*/

#include "/players/nooneelse/sea/nautilus_rooms.h"

inherit "room/room";

object obj;

string what;

init() {
  ::init();

  add_action("enter", "enter");
  add_action("leave", "leave");
}

enter() {
  say(this_player()->query_name()+" enters the bridge of the ship.\n");
  tell_room(BRIDGE,
            this_player()->query_name()+" enters the bridge of the ship.\n");
  move_object(this_player(), BRIDGE);
  command("look", this_player());
  return 1;
}

leave() {
  if (call_other(BRIDGE, "query_nautilus_docked", 0)) {
    say(this_player()->query_name()+
        " crosses the plank and stands on the dock.\n");
    if (call_other(BRIDGE, "query_nautilus_docked", 0)==1)
      move_object(this_player(), BLUEENTRY);
    if (call_other(BRIDGE, "query_nautilus_docked", 0)==2)
      move_object(this_player(), ISLAND_DOCK);
    command("look", this_player());
    what=" crosses the plank and stands on the dock";
    if (call_other(BRIDGE, "query_nautilus_docked", 0)==1)
      tell_room(BLUEENTRY, this_player()->query_name()+what+".\n");
    if (call_other(BRIDGE, "query_nautilus_docked", 0)==2)
      tell_room(ISLAND_DOCK, this_player()->query_name()+what+".\n");
    return 1;
  }
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("aft deck");
  no_castle_flag=1;
  return;
}

long() {
  write(
"This is the aft deck of a strange metal ship.  It is made of steel\n"+
"plates riveted together.  It has a serrated spine and two bulbous eye-like\n"+
"portholes.  You can enter the bridge from here or you can leave the ship\n"+
"via a gangway when the ship is in a habour.\n");
  if (call_other(BRIDGE, "query_nautilus_docked", 0))
    write("    There are two obvious exits: enter and leave\n");
  else
    write("    There is one obvious exit: enter\n");
}

look_in_porthole() {
  write("Inside the porthole, you see:\n");
  call_other(OBSERVATION_ROOM, "???", 0);
  call_other(OBSERVATION_ROOM, "long", 0);
  write("\n");
  obj = first_inventory(OBSERVATION_ROOM);
  while(obj) {
    if (obj->query_short()) write(obj->query_short()+"\n");
    else
    if (obj->query_name()) write(obj->query_name()+"\n");
    obj = next_inventory(obj);
  }
  tell_room(OBSERVATION_ROOM,
            "You see "+this_player()->query_name()+
            " looking in the observation port.\n");
  return 1;
}

id(str) {
  if (str=="porthole" || str=="portholes" || str=="port") {
    look_in_porthole();
    return 1;
  }
}
