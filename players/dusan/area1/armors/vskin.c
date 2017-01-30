#include "/players/dusan/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("skin");
set_alias("cloak");
set_short(""+BOLD+""+BLK+"Vraaak"+NORM+" skin cloak");
set_long(
  "A long black scaled cloak made from the hide of a vraaak.\n");

set_ac(1);
set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(500);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

