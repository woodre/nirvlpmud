inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tYou begin to notice that your thoughtforms are becoming less\n"+
"  and less cluttered... The intensity of your thinking remains the same,\n"+
"  and you begin to hum in an effort to stay awake, but it isnt sleepiness\n"+
"  that is overwhelming you, but the brand new concept of thoughtless\n"+
"  awareness... Is this mental state truly nirvana?\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/snorri.c",
    "players/mizan/etheriel/beasties/woogle.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/hoojib.c",
    "players/mizan/etheriel/beasties/tacoban.c"
  });
  ::extra_reset();
  if(1==random(1500)) {
  move_object(clone_object("players/mizan/etheriel/heals/twinkie.c"), this_object());
  }
}
