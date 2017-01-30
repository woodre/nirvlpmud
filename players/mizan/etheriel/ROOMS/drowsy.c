inherit "players/mizan/closed/RandomRoom.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc="Plane of Etheriel";
  long_desc="\tFeeling as you are being watched, a tingling flight of nervous\n"+
"  excitement rockets up your spine. About-facing you is a transparent\n"+
"  'creature', visible only by the further distortion of light its 'body'\n"+
"  creates. Suddenly, the field flickers and fades away, and you see the\n"+
"  image of a young girl.\n";
}

extra_reset() {
  object_names=({
    "players/mizan/etheriel/environs/girl.c"
  });
  ::extra_reset();
}
