id(str) { return str == "troll"; }
short() { return "A smelly troll"; }
long() {
  write("This is a big, smelly troll.\n");
}

init() {
  tell_room(environment(this_object()),
  "A smelly troll from a vanilla LPmud is blown to bits.\n");
  destruct(this_object());
  return 1;
}

can_put_and_get() { return 1; }

reset() {
  move_object(clone_object("players/mizan/etheriel/heals/ham.c"), this_object());
  move_object(clone_object("players/mizan/etheriel/items/wooly"), this_object());
}

