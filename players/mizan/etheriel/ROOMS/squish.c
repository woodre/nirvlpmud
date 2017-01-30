inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tThere are people who find thinking their way about an area\n"+
"  rather pleasant. The prospect of manouvering around strictly by thinking\n"+
"  about it (This 'astral' experience) they would die for. No matter your\n"+
"  opinion in the beginning, you are discovering that your brain is not\n"+
"  adjusting well to dealing with tracking objects in a four-dimensional\n"+
"  scenario, which this closely resembles.   \n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/squish.c",
    "players/mizan/etheriel/beasties/carton.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/hoojib.c",
    "players/mizan/etheriel/environs/faucet.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/twinkie.c"), this_object());
  }
}
