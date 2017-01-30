#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "obj/armor";

reset(arg) {
set_name("armor");
set_short("a worn suit of armor");
set_long(
  "  You see that this suit has taken much damage and is nearly\n"+
  "useless. Long burn marks and cuts made by claws can be found\n"+
  "on its breast plate and back.  It is covered in dried blood.\n");

set_ac(2);
set_type("armor");
set_weight(2);
set_value(100);
}

	
