inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tFor some reason, this area resembles a place you once dreamt\n"+
"  of as a child... A crawling sensation of deja vu strikes you, the first\n"+
"  sensation you feel being that of fear... As you settle in, and your\n"+
"  heartbeat slows down, the fear gives way to curiousity. It's just\n"+
"  a little spooky how the swirling environment you are in resembles\n"+
"  a delirious dream once had many moons ago.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/lost-wombat.c",
    "players/mizan/etheriel/beasties/woogle.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/giraffe.c"
  });
  ::extra_reset();
}
