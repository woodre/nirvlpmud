inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tWho would believe you if you told them about this place?\n"+
"  Who would even care? If you took someone else here to show them, it\n"+
"  may just alleviate the ridicule you get for describing an 'area with\n"+
"  a tub of jello' as the portalway. But then you would be subjecting\n"+
"  them to unneccessary torture, as they wander and try to escape this\n"+
"  realm for hours. An evil grin forces its way onto your face.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/grimpo.c",
    "players/mizan/etheriel/beasties/fuzzy.c",
    "players/mizan/etheriel/beasties/sarawak-turbo.c",
    "players/mizan/etheriel/beasties/blinking-boofer.c"
  });
  ::extra_reset();
}
