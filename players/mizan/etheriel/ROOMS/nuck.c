inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tSomething big just collided into your head. Taken completely\n"+
"  by surprise, you've become accustomed to things passing through your\n"+
"  body, and forgot that your own world is not like this one.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/machine.c",
    "players/mizan/etheriel/items/nitro-glycerin.c",
    "players/mizan/etheriel/beasties/oofa.c",
    "players/mizan/etheriel/beasties/boink.c"
  });
  ::extra_reset();
  if(1==random(10)) {
  move_object(clone_object("obj/level_list"), this_object());
  }
}

query_S7() { return 1; }
