#include "/players/fakir/color.h"
inherit "obj/armor";

reset(arg) {
set_name("cloak");
set_alias("grey cloak");
set_short(BOLD+GREEN+"Cloak of Healing"+OFF);
set_long(
  "A "+BOLD+GREEN+"Cloak of Healing"+OFF+" worn by village wisdoms in the realm of magic.\n"+
  "It is a symbol worn by those who have mastered the magical art of\n"+
  "healing, dream interpretation, and weather casting. The cloak glows\n"+
  "from the magic contained within.\n");

set_ac(1);
set_type("misc");
set_weight(1);
set_value(1000);
set_arm_light(1); 
}

