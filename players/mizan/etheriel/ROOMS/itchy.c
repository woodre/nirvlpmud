inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tSwirling masses of color pass through your body. You are not\n"+
"  getting used to this very well... Movement in this realm is a strange\n"+
"  new thing, accomplished by thinking of certain words... There is an\n"+
"  intense light source coming from the... the... oh.... nevermind.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/boink.c",
    "players/mizan/etheriel/beasties/spuckball-b.c",
    "players/mizan/etheriel/beasties/boofer.c",
    "players/mizan/etheriel/beasties/grimpo.c",
    "players/mizan/etheriel/environs/walesign.c"
  });
  ::extra_reset();
}

