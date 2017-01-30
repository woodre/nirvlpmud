#include "/players/dusan/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("boots");
set_alias("boots");
set_short(""+BOLD+""+HIW+"Bone"+NORM+" plated boots.");
set_long(
  "Black leather boots with bone plating.\n");

set_ac(1);
set_params("magical",1,0,0);
set_params("other|evil",0,10,0);
set_params("other|good",0,-10,0);
set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(800);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

