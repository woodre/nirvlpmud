inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tA strange, blinking, noisy, and utterly disturbing looking\n"+
"  'creature' is hovering in the 'center' of this 'room'. You are not too\n"+
"  thrilled with it, and the 'creature' seems to notice that you are\n"+
"  clearly not impressed with the lightshow. So, it decides to make \n"+
"  noise, too.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/blinking-boofer.c",
    "players/mizan/etheriel/beasties/waterlemon2.c",
    "players/mizan/etheriel/beasties/beano.c",
    "players/mizan/etheriel/beasties/wub.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/items/blockbuster.c"), this_object());
  }
}
