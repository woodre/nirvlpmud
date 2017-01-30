#include "/players/jaraxle/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("boots");
   set_alias("fire boots");
   set_long(
      "These boots cast an "+HIR+"eternal flame"+NORM+".  They feel warm\n"+
      "yet not scalding hot.  "+HIR+"Flames"+NORM+" whip around the boots\n"+
      "wrapping them in fire.  The boots offer difinitive\n"+
      "protection against any smoldering hot floored surface.\n");
   
   set_ac(2);
   set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(1500);
   set_arm_light(1);  /*  makes armor glow if it's > 0  */
}
short(){ return "Boots of the "+RED+"Eternal "+HIR+"["+HIY+"flaming"+HIR+"]"+NORM+""+(worn_by?" ("+HIR+"worn"+NORM+")":""); }
id(str){ return str == "jars_fire_boots" || str == "FIRE_BOOTS" || str == "eternal boots" || str == "boots"; }

query_save_flag(){ return 1; }
