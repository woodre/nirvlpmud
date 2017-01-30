#include "/players/dusan/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("plate");
set_alias("armor");
set_short("A "+HIW+"bone"+NORM+" breastplate");
set_long(
  "A light weight armor made from the bones of a human skeleton.\n");

set_ac(3);
set_params("magical",2,0,0);
set_params("other|evil",0,15,0);
set_params("other|good",0,-15,0);
set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(2);
set_value(900);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

