inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tEverlasting things are so hard to come by in this realm.\n"+
"  Deep down inside, you are beginning to enjoy it here, due to the\n"+
"  absence of any kind of rule. It is a utopian society in a sense, \n"+
"  complete anarchy and freedom... yet stability and innocence exist.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/lost-wombat.c",
    "players/mizan/etheriel/beasties/oomingmak.c",
    "players/mizan/etheriel/beasties/spuckball.c"
  });
  ::extra_reset();
  if(1==random(10)) {
  move_object(clone_object("players/mizan/etheriel/beasties/hoojib.c"), this_object());
  }
}
