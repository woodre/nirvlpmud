/* Sash from Chess without the special */

#include "/players/jareel/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("demon belt");
   set_alias("belt");
   set_short(HIK+"Demon Belt "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM);
   set_long(
      "The Demon Belt is forged in Yelms Sun fire. An ancient practice\n"+
      "that releases chaotic powers in a protective shell.\n");
   set_light(1);
   set_ac(2);
   set_type("belt");
   set_weight(1);
   set_value(12000);
}
