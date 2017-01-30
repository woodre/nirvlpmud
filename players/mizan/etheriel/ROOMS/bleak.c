inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tAs your sense of nausea fades and turns to that of wonderful\n"+
"  childlike glee, you cant help but let out an assorment of 'whoas!' and\n"+
"  'whees!'. An intense craving for adventure suddenly develops, hitting\n"+
"  you like a freight train colliding into a puppy dog.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/boink.c",
    "players/mizan/etheriel/beasties/colormonger.c",
    "players/mizan/etheriel/beasties/spucktrooper.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/beasties/sarawak-turbo.c",
  });
  ::extra_reset();
  if(1==random(100)) {
  move_object(clone_object("players/mizan/etheriel/items/poohbear.c"), this_object());
  }
}
