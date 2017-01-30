inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tA terrifying sight unfolds before you, as you hear the thundering\n"+
"  of a distant explosion, then see the unpredictable meandering paths of\n"+
"  the shockwaves come closer and closer to you. Just before they would\n"+
"  overcome you, a wandering Boofer pops into view and absorbs the brunt\n"+
"  of the shock. You are now left to peel Boofer remains off of yourself,\n"+
"  but at least you are alive.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/sofa.c",
    "players/mizan/etheriel/environs/hood.c",
    "players/mizan/etheriel/items/bmw-grille.c",
    "players/mizan/etheriel/beasties/something.c",
    "players/mizan/etheriel/beasties/lost-wombat.c"
  });
  ::extra_reset();
}
