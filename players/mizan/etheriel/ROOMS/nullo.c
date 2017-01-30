inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tSomething large and sticky suddenly fades into view and passes\n"+
"  on by. It leaves you covered in a gooey mess of some sort. Clenching\n"+
"  your fist at it, you curse and yell violently, but to no avail. Left\n"+
"  with the rather undesirable chore of cleaning the stuff off yourself,\n"+
"  some of it slips into your mouth. Mmmm. Tastes like... green... lime\n"+
"  flavored jello-stuff. Maybe it was'nt so bad after all...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/snurfle.c",
    "players/mizan/etheriel/beasties/mr-rogers.c",
    "players/mizan/etheriel/beasties/snorri.c",
    "players/mizan/etheriel/beasties/hoojib.c"
  });
  ::extra_reset();
  if(1==random(1000)) {
  move_object(clone_object("players/mizan/etheriel/environs/ladyl.c"), this_object());
  }
}
