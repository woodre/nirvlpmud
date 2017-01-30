#pragma strong_type

inherit "room/room";

void reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_short("A small dirty cell");
  set_long("In a small dirty cell.\n");
  dest_dir = ({ "players/kantele/dungeon_corridor", "east" });
}

void init() {
  ::init();
  add_action("gate_check", "east");
}

status gate_check() {
  if ("players/kantele/guard_room"->query_gate3()) {
    write("The celldoor is closed.\n");
    return 1;
  }
  this_player()->move_player("east#players/kantele/dungeon_corridor");
  return 1;
}
