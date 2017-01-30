#include "/players/catacomb/misc/ansi.h"
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("tunic");
  set_short("A fine elven tunic");
  set_long(
    "The tunic is of fine elven origin.  The small chains interlock\n"+
    "forming a formidible wall for any weapons to get through.\n");
  set_type("armor");
  set_ac(3);
  set_weight(2);
  set_value(1500);
}
