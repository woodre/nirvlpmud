#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "obj/armor";

reset(arg) {
set_name("cloak");
set_short(HIW+"An overcloak of shadow"+NORM);
set_long(
  "  Looking closely you see this cloak is slightly worn, but otherwise is\n"+
  "is made of the finest fabric you have ever seen. Woven into it are numerous\n"+
  "symbols of magic, just slightly visible in the fabric. It is beautiful.\n");
set_ac(2);
set_type("misc");
set_weight(1);
set_value(200);
}

	
