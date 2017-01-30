#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "obj/armor";

reset(arg) {
set_name("shield");
set_alias("mals_shadow_shield");
set_short(""+BOLD+""+BLK+"Gothic Shield of Shadows"+NORM+"");
set_long(
  "  This shield was once used by the Archangel of Shadows. It's shiney\n"+
  "black surface seems very resistant to attack.\n");

set_ac(2);
set_type("shield");
set_weight(2);
set_value(1000);
}

	
