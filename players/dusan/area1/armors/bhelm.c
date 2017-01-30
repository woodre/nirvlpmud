#include "/players/dusan/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("skull");
set_alias("helm");
set_short("A "+BOLD+""+HIW+"bone"+NORM+" helm");
set_long(
  "A bleached bone helm made from a hollowed out skull.\n");

set_ac(1);
set_params("other|good",0,-10,0);
set_params("other|evil",0,10,0);
set_params("magical",1,0,0);
set_type("helmet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(900);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

