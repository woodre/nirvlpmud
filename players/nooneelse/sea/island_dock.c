/*
 island_dock.c - entrance/exit to/from the deck of the nautilus at the island
*/

#include "/players/nooneelse/sea/nautilus_rooms.h"

inherit "room/room";

object obj;
string str;

init() {
  ::init();

  add_action("up",    "up");
  add_action("board", "board");
}

up() {
  say(this_player()->query_name()+" leaves up the stairs.\n");
  move_object(this_player(), "players/nooneelse/sea/island_hall");
  command("look", this_player());
  return 1;
}

board() {
  if (call_other(BRIDGE, "query_nautilus_docked", 0)==2) {
    tell_room(DECK, this_player()->query_name()+
              " crosses the plank and stands on the deck of the ship.\n");
    move_object(this_player(), DECK);
    command("look", this_player());
    return 1;
  }
}

look_at_ship(str) {
  if (!str) return;
  if (str != "ship" && str != "nautilus") return;
  if (call_other(BRIDGE, "query_nautilus_docked", 0)==2) {
    write("It is a strange ship, made of steel plates riveted together.\n");
    return 1;
  }
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("dock");
  no_castle_flag=1;
  return;
}

long() {
  write("You are in a huge cavern.  The bottom is filled with water.\n"+
        "There is a sturdy wooden dock and a stairway leading up.\n"+
        "If you wait long enough a ship may come by and give you passage.\n");
  if (call_other(BRIDGE, "query_nautilus_docked", 0)==2) {
    write("There is a strange metal ship tied to the dock.\n"+
          "    There are two obvious exits: up and board\n");
  }
  else
    write("    There is one obvious exit: up\n");
}

id(str) {
  if (str=="ship" || str=="nautilus") {
    look_at_ship("ship");
    return 1;
  }
}
