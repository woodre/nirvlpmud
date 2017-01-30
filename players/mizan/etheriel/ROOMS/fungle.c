inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tGrabbing your attention immediately is the hideous freak of\n"+
"  nature that hovers before you. You are utterly speechless. Never in\n"+
"  your life have you seen such a thing, and you wonder what kind of\n"+
"  sick deity could have created this poor beast.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/giraffe.c",
    "/players/mizan/etheriel/beasties/oofa.c",
    "/players/mizan/etheriel/beasties/grimpo.c",
    "/players/mizan/etheriel/beasties/grimpo.c",
    "players/mizan/etheriel/beasties/wub.c"
  });
  ::extra_reset();
  if(1==random(2110)) {
  move_object(clone_object("players/mizan/etheriel/heals/portable_cow.c"), this_object());
  }
}
