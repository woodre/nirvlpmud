#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("dress");
set_alias("dress");
set_short(""+HIW+"A white wedding dress"+NORM+"");
set_long(
   "   Ceres' wedding dress is made by white silk and has a v-necked \n"+
   "shape which shows a little of her ample cleavage.  The veil is \n"+
   "adorned by a crown of small sterling roses and holds a long train \n"+
   "which reaches the floor and more.\n");

set_ac(1);
set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(4000);
set_arm_light(0);  /*  makes armor glow if it's > 0  */
}

