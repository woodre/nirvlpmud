#include "/players/feldegast/defines.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("circle");
  set_alias("summoning_circle");
  set_short(BOLD+"A summoning circle"+NORM);
  set_long(
"Intricate runes, drawn with a chalky white substance that seems\n\
to glow slightly, are drawn into the ground, forming a circle.\n");
  set_weight(99);
  set_value(0);
}
get() { return 0; }

