#include "/players/dusan/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("shield");
set_alias("shield");
set_short(""+BOLD+""+HIW+"Bone"+NORM+" shield");
set_long(
  "A bone shield made from the bones of various creatures.\n");

set_ac(1);
set_params("magical",1,0,0);
set_params("other|good",0,-10,0);
set_params("other|evil",0,10,0);
set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(800);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

