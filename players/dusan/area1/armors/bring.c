#include "/players/dusan/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("gauntlets");
set_alias("gloves");
set_short(""+BOLD+""+HIW+"Bone"+NORM+" plated gauntlets");
set_long(
  "Black leather gloves with bone plating.\n");

set_ac(1);
set_params("magical",1,0,0);
set_params("other|evil",0,10,0);
set_params("other|good",0,-10,0);
/* params added by illarion may 2005 */
set_type("gloves");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(800);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

