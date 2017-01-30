inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
long_desc="\tYour curiosity is drawn to a small, spinning object sitting\n"+
"  relatively still, emitting wild bursts and pulses of energy. As you\n"+
"  drift nearer to it, it disappears with a soft squishing sound. You\n"+
"  feel the tug of a massive current pull you towards where that object\n"+
"  once was. Eventually, the pressures around you stabilize and you\n"+
"  stop drifting.\n";
}

extra_reset() {
  ::extra_reset();
  object_names=({
    "players/mizan/etheriel/beasties/snurfle.c",
    "players/mizan/etheriel/beasties/spuckball-b.c",
    "players/mizan/etheriel/beasties/blinking-oofa.c",
    "players/mizan/etheriel/beasties/lost-wombat.c"
  });
  ::extra_reset();
  if(1==random(1100)) {
  move_object(clone_object("players/mizan/etheriel/heals/pickles.c"), this_object());
  }
}
