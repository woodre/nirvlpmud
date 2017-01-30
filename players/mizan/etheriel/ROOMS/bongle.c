inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tA sweetly pleasant smell greets you as you think your way here.\n"+
"  it is the smell of oranges and elsewhere, you can pick up a faint trace\n"+
"  of what appears to be buttercups. Wave of playful Spuckballs dart\n"+
"  back and forth, leaving a thin strand of multihued spirals in their\n"+
"  wakes. You feel gleeful and it feels heavenly to just stretch out and\n"+
"  drift in the soft, predictable current.\n";
}

extra_reset() {
  object_names=({
     "players/mizan/etheriel/beasties/cactus.c",
     "players/mizan/etheriel/beasties/spuckball.c",
     "players/mizan/etheriel/beasties/spuckball.c",
     "players/mizan/etheriel/beasties/beano.c", 
     "players/mizan/etheriel/environs/spigot.c"
  });
  ::extra_reset();
  if(1==random(1500)) {
  move_object(clone_object("players/mizan/etheriel/heals/dirtbag.c"), this_object());
  }
}
