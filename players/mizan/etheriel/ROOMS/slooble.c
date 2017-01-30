inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tYou realize that extended exposure to this realm does not\n"+
"  produce the narcotic effect as desired. The wacky 'high' comes when\n"+
"  rapid movement occurs and you are spungled and zokked from place to\n"+
"  place at a blisteringly rapid pace. Such an experience may be emulated\n"+
"  by surfing, skiing, skydiving, bungee-jumping, and rock climbing all\n"+
"  in the brief period of an hour.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/giraffe.c",
    "players/mizan/etheriel/beasties/zok.c",
    "players/mizan/etheriel/beasties/breeder-monk.c"
  });
  ::extra_reset();
  if(1==random(3000)) {
  move_object(clone_object("players/mizan/etheriel/heals/pickles.c"), this_object());
  }
}
