#include "/players/fred/ansi.h"
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("belt");
  set_short(RED+"Red"+NORM+" belt of kung-fu");
  set_long(
  "  A small red belt that once belonged to a martial artist.\n");
  set_type("belt");
  set_ac(1);
  set_weight(1);
  set_value(675);
}
