inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tA dizzying variety of useless items suddenly drift by, and\n"+
"  with the blink of the eye, you see a toy action figure, a screw eye, a\n"+
"  thimble, and a bag of marbles vanish into thin air.\n";
}

extra_reset() {
  object_names=({
  "players/mizan/etheriel/beasties/captain-battery.c",
  "players/mizan/etheriel/environs/plug.c",
  "players/mizan/etheriel/environs/blue-button.c"
  });
  ::extra_reset();
}
