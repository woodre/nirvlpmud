#include "/players/catacomb/misc/ansi.h"
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("robe");
  set_short("A dark robe");
  set_long(
    "  A dark cloak that almost seems to absorb all the light in the room.\n"+
    "The strange thing about it is that it looks to be very large but it\n"+
    "feels as light as a feather.\n");
  set_type("armor");
  set_ac(3);
  set_weight(1);
  set_value(1500);
}
