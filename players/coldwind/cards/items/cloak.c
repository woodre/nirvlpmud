#include "/players/coldwind/define.h"
inherit "obj/armor";

reset(arg) {
set_name("cloak");
set_alias("misc");
set_short(HIW+"Fl"+NORM+RED+"ow"+HIW+"ing Cl"+NORM+RED+"oa"+HIW+"k of the Pr"+NORM+RED+"in"+HIW+"ce"+NORM);
set_long(
"A white silk cloak with a big red heart in the middle. It looks like\n"+
"it was worn by royality and should provide good protection not doubt.\n"+NORM);
set_ac(2);
set_type("misc");  
set_weight(1);
set_value(1200);
}
