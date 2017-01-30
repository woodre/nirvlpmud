#include "/players/dusan/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("necklace");
set_alias("amulet");
set_short(""+BOLD+""+HIW+"Bone"+NORM+" amulet");
set_long(
  "An amulet made from the teeth of fallen warriors.\n");

set_ac(1);
set_params("magical",1,0,0);
set_params("other|evil",0,10,0);
set_params("other|good",0,-10,0);
set_type("amulet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(800);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

