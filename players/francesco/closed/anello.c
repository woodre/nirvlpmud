#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("ring");
set_short(""+HIC+"A platinum ring"+NORM+"");
set_long(
   "       This simple ring has some engravings on it\n\n"+
   "                      The warriors\n"+
   "              Lady Sparkle and Lord Horus \n"+
   "                    in love forever\n\n"+
   "                   October 29th, 2001\n");
set_value(0);
set_ac(22);
set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_arm_light(1);  /*  makes armor glow if it's > 0  */
}
