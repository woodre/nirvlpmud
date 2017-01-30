#include "/players/catacomb/misc/ansi.h"
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("cloak");
  set_short("A "+BLK+"dark"+NORM+" cloak");
  set_long("  The cloak chosen by the scouts of the Durkor for its ability\n"+
           "to blend into their surroundings of the caverns.\n");
  set_type("misc");
  set_ac(1);
  set_weight(1);
  set_value(600);
}
