/* Dragon Pants */

#include "/players/jareel/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("demon pants");
   set_alias("vambraces");
   set_short(HIK+"Demon Vambraces "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM);
   set_long(
      "The Demon pants is forged in Yelms Sun fire. An ancient practice\n"+
      "that releases chaotic powers in a protective shell.\n");
   set_light(1);
   set_ac(1);
   set_type("pants");
   set_weight(1);
   set_value(12000);
}
