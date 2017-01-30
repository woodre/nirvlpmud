#include "/players/dusan/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("shield");
set_alias("shield");
set_short(""+BOLD+""+BLK+"Vraaak"+NORM+" skin shield");
set_long(
  "A bone shield covered in the thick scaly hide of the vraaak.\n");

set_ac(1);
set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(1000);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

