#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("ring");
set_short("A golden ring");
set_long(
   "\n       This simple ring has some engravings on it\n"+
   "   "+HIW+"Lady Myra the Bard    and    Lord Beez the Paladin\n"+NORM+
   "                   in love forever\n"+
   "                   May 18th, 1983\n\n");
set_value(300);
set_ac(1);
set_type("ring");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_arm_light(1);  /*  makes armor glow if it's > 0  */
}
