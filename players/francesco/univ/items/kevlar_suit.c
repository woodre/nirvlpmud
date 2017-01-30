#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("suit");
set_alias("armor");
set_short("A kevlar suit");
set_long(
   "   This kevlar suit has been tested deeply and will hopefully be\n"+
   "worn by policemen or soldiers when engaged in dangerous combats.\n"+
   "It is very light and decently protective, making it particularly\n"+
   "suitable in urban engagements where the velocity of the movements\n"+
   "is a must.\n");

set_ac(3);
set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(3500);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

