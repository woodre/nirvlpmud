#include "/players/jareel/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("demon armor");
   set_alias("armor");
   set_short(HIK+"Demon Platemail "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM);
   set_long(
      "Demon Plate mail is forged in the sun fire of Yelm, a ancient practice\n"+
      "that turns chaotic flesh into a protective shell.\n");
   set_light(2);
   set_ac(4);
   set_type("armor");
   set_weight(2);
   set_res(10);
   set_value(12000);
}
