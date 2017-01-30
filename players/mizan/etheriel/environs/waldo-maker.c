id(str) { return str == "waldo-maker"; }
short() { return 0; }
long() { return 0; }

reset() {
  string destination;
  destination=call_other("/players/mizan/closed/RandomRoomDM", "one_random", 0);
  move_object(clone_object("players/mizan/etheriel/beasties/waldo"), "players/mizan/etheriel/ROOMS/" + destination);
  destruct(this_object());
  return 1;
}
