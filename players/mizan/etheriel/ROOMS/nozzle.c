inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tOuch! Ouch! Ouch!\n"+
"  Apparently, you have wandered into an area cluttered with steel wool\n"+
"  and thumbtacks. Lucky for you they were'nt fishing nets and kitchen\n"+
"  knives, or you would be in big trouble. But maybe you could cut the\n"+
"  nets with the kitchen knives? No. If you were trapped you could'nt\n"+
"  even reach them. Yups.\n";
}

query_zokko() { return "Zooooooom!"; }

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/roz.c",
    "players/mizan/etheriel/beasties/grimpo.c",
    "players/mizan/etheriel/beasties/blinking-boofer.c",
    "players/mizan/etheriel/beasties/silent.c",
  });
  ::extra_reset();
  if(1==random(2)) {
  move_object(clone_object("players/mizan/etheriel/beasties/spuckball.c"), this_object());
  }
}

