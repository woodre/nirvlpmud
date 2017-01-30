inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tBasking in the rich, warm glow of a spasmodically \n"+
"  blinking Grimpo, you are interrupted by something that phases\n"+
"  through your arm and leaves a sticky, gooey, slime on it.\n"+
"  Eeewwww.  Then, just as you move to clean it off, a bowling\n"+
"  ball collides with your head. Doh!\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/blinking-grimpo.c",
    "players/mizan/etheriel/beasties/lost-wombat.c",
    "players/mizan/etheriel/beasties/spuckball.c",
    "players/mizan/etheriel/items/bowling-ball.c"
  });
  ::extra_reset();
}
