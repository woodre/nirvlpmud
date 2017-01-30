inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tWhen you drift into this part of the ether-muck, you notice\n"+
"  that the nearby 'creatures' drift away from you as if you were a leper.\n"+
"  Somewhat foozled by their behavior (They normally don't run away) you\n"+
"  are left to ponder alone what could have caused the disturbance.\n";
}

init() {
  ::init();
  if(!present("explodey", this_object())) {
    move_object(clone_object("players/mizan/etheriel/environs/exploder.c"), this_object());
   }
}
extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/silent-beano.c"
  });
  ::extra_reset();
}
