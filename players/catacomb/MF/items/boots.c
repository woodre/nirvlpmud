#include "/players/catacomb/misc/ansi.h"
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("boots");
  set_short("A pair of boots");
  set_long(
   "  A simple pair of knee high boots made from deer skin.\n");
  set_type("boots");
  set_ac(1);
  set_weight(1);
  set_value(500);
}
