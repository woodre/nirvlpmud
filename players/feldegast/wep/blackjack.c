#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("blackjack");
  set_short("Blackjack");
  set_long(
    "This is a long blunt instrument, used for knocking somebody\n"+
    "upside the head, or for delivering a beating rather than\n"+
    "combat.\n"
  );
  set_type("club");
  set_class(13);
  set_weight(1);
  set_value(100);
}
