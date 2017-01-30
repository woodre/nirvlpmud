#include "/players/languilen/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
     set_name("shield");
     set_alias("body shield");
     set_short("Personal Body Shield");
     set_long(
"    This is a non approved item.  Any player using this had better be\n\
a test character!\n");

     set_ac(9);
     set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
     set_weight(1);
     set_value(0);
     set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

