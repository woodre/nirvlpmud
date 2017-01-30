#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  if(arg) return;
  ::reset();
  set_name("flail");
  set_short("A flail");
  set_type("polearm");
  set_long(
"The flail is a weapon commonly found on farms, and used to\n"+
"thresh grain.  It is a long pole with a free swinging stick\n"+
"on the end.\n");
  set_weight(4);
  set_class(15);
  set_value(700);
}
