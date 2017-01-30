#include "/players/dusan/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("skin");
set_alias("boots");
set_short(""+BOLD+"vraaak"+NORM+" skin armor");
set_long(
  "Scaled, black, hard leather main armor made from the hide of a vraaak.\n");

set_ac(2);
set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(900);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

