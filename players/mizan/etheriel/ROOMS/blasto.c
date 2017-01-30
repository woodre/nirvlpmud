inherit "players/mizan/closed/RandomRoom.c";

reset() {
  ::reset();
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tSomething that looks like the remains of a trailer grab your\n"+
"  attention. It is colored in a most tasteless shade of pink, and a\n"+
"  assortment of sounds are coming from it. Instruments sounding like\n"+
"  mandolins tweaked by the Devil and singing meant for no-one's ears\n"+
"  shatter the murky organic background of this truly odd realm.\n";
}

extra_reset() {
  object_names=({
   "/players/mizan/etheriel/beasties/oofa.c",
    "players/mizan/etheriel/environs/trailer.c",
    "players/mizan/etheriel/beasties/elvis.c",
    "players/mizan/etheriel/beasties/screaming-girl.c",
    "players/mizan/etheriel/beasties/screaming-girl.c",
    "players/mizan/etheriel/beasties/dummy.c"
  });
  ::extra_reset();
  if(1==random(500)) {
  move_object(clone_object("players/mizan/etheriel/items/lego.c"), this_object());
  }
}
