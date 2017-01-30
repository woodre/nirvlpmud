inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tYou can imagine no better form of torture for the impatient\n"+
"  personality than to have them wander about here unguided throughout\n"+
"  the realm. Meanwhile, scattered all around you are what appears to be\n"+
"  the evidence of a massive player-killing fest. Empty bottles and\n"+
"  spent heals drift about in the ether-muck before you, as well as a\n"+
"  clutch of broken weapons and shattered armors.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/sarawak.c",
    "players/mizan/etheriel/beasties/moogle.c",
    "players/mizan/etheriel/beasties/blinking-boofer.c"
  });
  ::extra_reset();
}
