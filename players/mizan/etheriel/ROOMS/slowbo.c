inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tBubbling and gurgling with the innocent curiousity of a child,\n"+
"  something snaps your attention away from the Beano you are torturing.\n"+
"  A massive ripple-shockwave is heading your way. Hearing the deafening\n"+
"  explosion first, and then seeing and eventually getting caught up in\n"+
"  the extremely nogglesome energy wave, you could only utter a soft 'shit',\n"+
"  while you peel off the entrails of whatever it was that smashed into\n"+
"  you. Ick.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/beasties/beano.c",
    "players/mizan/etheriel/beasties/nogbeast.c",
    "players/mizan/etheriel/beasties/bernard.c"
  });
  ::extra_reset();
}
