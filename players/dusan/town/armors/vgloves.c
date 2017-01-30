#include "/players/dusan/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("skin");
set_alias("gloves");
set_short(""+BOLD+"vraaak"+NORM+" skin gloves");
set_long(
  "Scaled, black, leather gloves made from the hide of a vraaak.\n");

set_ac(1);
set_type("ring");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(500);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

