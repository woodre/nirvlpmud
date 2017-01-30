inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tStrange thoughts grace your mind... You begin to dream or even\n"+
"  hallucinate about rolling grassy hills and knolls, of hot crossed buns\n"+
"  and mutton stew... Suddenly, you are struck by a speeding Spuckball and\n"+
"  the rich green landscapes in your mind give way to the green multihues\n"+
"  that dominate this part of the realm.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/lost-wombat.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/punk.c"
  });
  ::extra_reset();
}
