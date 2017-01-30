inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tThe consistency of this funky place keeps changing, and that\n"+
"  drives you a bit wacky. Some places, you feel lighter than air, as you\n"+
"  can almost imagine being able to see right through yourself. In other\n"+
"  places, you feel as slow and sluggish as tar. That bites. Right now,\n"+
"  you are in a compromise of the two places, an area of liquid-like\n"+
"  consistency.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/snorri.c",
    "players/mizan/etheriel/beasties/colormonger3.c",
    "players/mizan/etheriel/beasties/grimpo.c",
    "players/mizan/etheriel/environs/spigot.c"
  });
  ::extra_reset();
  if(1==random(400)) {
  move_object(clone_object("players/mizan/etheriel/heals/orange.c"), this_object());
  }
}
