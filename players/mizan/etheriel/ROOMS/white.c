inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tA strange, uneasy feeling works its way into your gut. It is the\n"+
"  same feeling one gets when falling off of a skyscraper, and awaiting\n"+
"  impending doom. You are not too sure why it happened, but you find that\n"+
"  there is a direct link between the 'happiness level' of the environment\n"+
"  and that of your own mood. Right now the colors swirling about form\n"+
"  composite images of things that look like what you would step on \n"+
"  occasionally on the street.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/moogle.c",
    "players/mizan/etheriel/beasties/cactus.c",
    "players/mizan/etheriel/beasties/spuckball-b.c",
    "players/mizan/etheriel/beasties/beano.c",
    "players/mizan/etheriel/beasties/ettin.c"
  });
  ::extra_reset();
}
