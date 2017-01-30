/* Inferior to Pentagram of Defense */

#include "/players/jareel/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("demon pendent");
   set_alias("pendent");
   set_short(HIK+"Demon Pendent "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM);
   set_long(
      "The Demon necklace is forged in Yelms Sun fire. An ancient practice\n"+
      "that releases chaotic powers in a protective shell.\n");
   set_light(1);
   set_type("necklace");
   set_weight(1);
   set_value(12000);
}
