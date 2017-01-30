#include "/players/wocket/closed/ansi.h"
inherit "/obj/armor.c";

reset(arg){
  if(arg) return;
set_id("hat");
set_short("A "+HIB+"postman's"+NORM+" hat");
set_long("An old faded hat worn by postmen.  Its blue with five point and in the front\n"+
"a shinny metal shimmers in light.  The bill is creased in many places.\n");
set_weight(2);
set_type("helmet");
set_ac(0);
set_value(100);
}
