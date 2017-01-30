inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tEverything seems slightly decelerated here, the 'current'\n"+
"  dies down to a preditable doldrum, and the colors lose an ounce of their\n"+
"  flash and luminesence. The sedating influence of the area calms you\n"+
"  down and causes you to hum for some odd reason.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/spud.c",
   "/players/mizan/etheriel/beasties/cactus.c",
   "/players/mizan/etheriel/beasties/oofa.c",
   "/players/mizan/etheriel/beasties/oofa.c",
   "/players/mizan/etheriel/beasties/Amelia.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/herring.c"), this_object());
  }
}
