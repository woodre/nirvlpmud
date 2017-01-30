#include "/players/wocket/closed/ansi.h"
inherit "obj/armor";

reset(arg){
set_name("ring");
set_alias("diamond ring");
set_short("A "+HIC+"diamond"+NORM+" ring");
set_long("There is a wonderful diamond in the center that sparkles with magic\n"+
"as it gleems in the light.  The band is gold and intricately decroated with\n"+
"many overlappings and folds.  This is the ring of Lady Vreeland.\n");
set_ac(1);
set_weight(1);
set_value(1000);
set_type("ring");
}

