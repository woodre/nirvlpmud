#include "/players/jareel/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("demon shield");
   set_alias("shield");
   set_short(HIK+"Demon Shield "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM);
   set_long(
      "The Demon Shield is forged in Yelms Sun fire. An ancient practice\n"+
      "that releases chaotic powers in a protective shell.\n");
   set_light(1);
   set_ac(1);
   set_type("shield");
   set_weight(1);
   set_res(2);
   set_value(12000);
}
