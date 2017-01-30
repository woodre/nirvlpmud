inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\t'Arriving' here, you discover that the current is especially\n"+
"  strong. Off in the far distance, you see a series of converging masses,\n"+
"  constantly changing colors and passing through one another. Beautiful\n"+
"  as it seems, you have the feeling that the forces involved in those\n"+
"  collisions would rip you to shreds, like a tidal wave...\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/spucktrooper.c",
    "players/mizan/etheriel/beasties/boofer.c",
    "players/mizan/etheriel/environs/seefeel.c"
  });
  ::extra_reset();
}
