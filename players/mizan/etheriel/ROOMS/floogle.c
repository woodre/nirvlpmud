inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tA pulsing, rhythmic beat can be felt, and it is so catchy that\n"+
"  you feel like 'dancing'. Moving and swaying your body to the beat, \n"+
"  the only thing you can do is give in to the funky new sound that\n"+
"  assaults you like none other. The 'music' itself is a collection of\n"+
"  of 'organic' sounds that would not stand alone, but united form the\n"+
"  the core of the most dance-able and groove-able beats you have ever known.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/tacoban.c",
    "players/mizan/etheriel/beasties/spuckball-b.c",
    "players/mizan/etheriel/beasties/snurfle.c",
    "players/mizan/etheriel/beasties/emo.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/heals/herring.c"), this_object());
  }
}
