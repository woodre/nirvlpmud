inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tJust as you float into this area, you are hit by a soft spongy thing,\n"+
"  which nails you in the stomach, and then passes through it. It then passes\n"+
"  through your head, and then for a brief moment, you experience its thoughts,\n"+
"  consisting mostly of simple emotions...\n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/environs/spigot.c",
  "players/mizan/etheriel/beasties/lost-wombat.c",
  "players/mizan/etheriel/beasties/blinking-oofa.c",
  "players/mizan/etheriel/beasties/spuckball.c"
  });
  ::extra_reset();
}
