inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\t'One more day of this mindless folly and we'll all go down\n"+
"  insane' is what you hear coming from a voice behind you. Snapping\n"+
"  about-face, you see, naturally, nothing. Hmm.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/wz-pinball.c",
    "players/mizan/etheriel/beasties/ziggle.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "obj/level_list.c"
  });
  ::extra_reset();
}
