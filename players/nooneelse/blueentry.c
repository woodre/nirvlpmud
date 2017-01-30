/*
 blueentry.c - entrance/exit to/from the deck of the nautilus
*/

#include "/players/nooneelse/sea/nautilus_rooms.h"

inherit "room/room";

object obj;
string str;

init() {
  ::init();

  add_action("south",        "south");
  add_action("board",        "board");
}

south() {
  say(this_player()->query_name()+" leaves south.\n");
  move_object(this_player(), "players/nooneelse/dim");
  command("look", this_player());
  return 1;
}

board() {
  string msg;
  if (call_other(BRIDGE, "query_nautilus_docked", 0)==1) {
    msg=this_player()->query_name()+
        " crosses the plank and stands on the deck of the ship.\n";
    tell_room(DECK, msg);
    move_object(this_player(), DECK);
    command("look", this_player());
    return 1;
  }
}

look_at_ship(str) {
  if (!str) return;
  if (str != "ship" && str != "nautilus") return;
  if (call_other(BRIDGE, "query_nautilus_docked", 0)==1) {
    write("It is a strange ship, made of steel plates riveted together.\n");
    return 1;
  }
}

reset(arg) {
  if (arg) return;

  set_light(1);
  short_desc=("dock");
  no_castle_flag=1;
/* wake up the entire ship */
  call_other(BLUEENTRY, "???", 0);
  call_other(ISLAND_DOCK, "???", 0);
  call_other(BELOW_DECK, "???", 0);
  call_other(BRIDGE, "???", 0);
  call_other(NIMO, "???", 0);
  call_other(CHART_ROOM, "???", 0);
  call_other(DECK, "???", 0);
  call_other(ENGINE_ROOM, "???", 0);
  call_other(OBSERVATION_ROOM, "???", 0);
  return;
}

long() {
  write("This is a sturdy wooden dock.  If you wait long enough\n"+
        "a ship may come by and give you passage.\n");
  if (call_other(BRIDGE, "query_nautilus_docked", 0)==1) {
    write("There is a strange metal ship tied to the dock.\n"+
          "    There are two obvious exits: south and board\n");
  }
  else
    write("    There is one obvious exit: south\n");
}

id(str) {
  if (str=="ship" || str=="nautilus") {
    look_at_ship("ship");
    return 1;
  }
}
