/* Yelmalian Elite Helm */

#include "/players/jareel/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("demon helm");
   set_alias("helm");
   set_short(HIK+"Demon Helm "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM);
   set_long(
      "The Demon helm is forged in Yelms Sun fire. An ancient practice\n"+
      "that releases chaotic powers in a protective shell.\n");
   set_light(2);
   set_ac(1);
   set_type("helmet");
   set_weight(1);
   set_value(12000);
}