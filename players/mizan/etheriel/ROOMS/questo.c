inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tA sudden feeling of hopelessness and general frustration\n"+
"  overwhelms you with a vengeance unparalled to anything you have ever\n"+
"  known... Screaming is futile, as well as lashing out at surrounding\n"+
"  objects (most of which phase harmlessly through you anyways). Your\n"+
"  stomach grumbles loudly, and you deduce that a sudden craving for\n"+
"  Oreo cookies was what made you momentarily irrational. Interesting.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/waterlemon.c",
    "players/mizan/etheriel/environs/quest-ht.c",
    "players/mizan/etheriel/beasties/mboofer.c",
    "players/mizan/etheriel/beasties/spuckball.c"
  });
  ::extra_reset();
  if(1==random(4)) {
  move_object(clone_object("players/mizan/etheriel/beasties/hoojib.c"), this_object());
  }
}

