#include "/players/jareel/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("demon shorts");
   set_alias("shorts");
   set_short(HIK+"Demon Shorts "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM);
   set_long(
      "The Demon Shorts are forged in Yelms Sun fire. An ancient practice\n"+
      "that releases chaotic powers in a protective shell.\n");
   set_light(1);
   set_ac(2);
   set_type("underwear");
   set_weight(1);
   set_value(12000);
}
