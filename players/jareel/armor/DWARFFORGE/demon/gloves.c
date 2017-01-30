/* Gloves of Moloch with no special */

#include "/players/jareel/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("demon gloves");
   set_alias("gloves");
   set_short(HIK+"Demon Gloves "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM);
   set_long(
      "The Demon gloves is forged in Yelms Sun fire. An ancient practice\n"+
      "that releases chaotic powers in a protective shell.\n");
   set_light(1);
   set_ac(2);
   set_type("gloves");
   set_weight(1);
   set_value(22000);
}