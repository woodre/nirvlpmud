#include "/players/feldegast/std/color_pad.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("wand");
  set_short("color test wand");
  set_long("Blah");
  set_weight(0);
}

init() {
  add_action("wave","wave");
}

wave(str) {
  string test;
  test=HIR+"Testing"+NORM;
  write(color_pad(test,30)+"|");
  write(pad(test,30)+"|");
  return 1;
}
