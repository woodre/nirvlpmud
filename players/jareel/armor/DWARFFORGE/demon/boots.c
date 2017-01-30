/* Work Boots from Trix */

#include "/players/jareel/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("demon boots");
   set_alias("boots");
   set_short(HIK+"Demon Boots "+NORM+"["+HIY+"Sun Forged"+NORM+"]"+NORM);
   set_long(
      "Demon Boots are forged in the sun fire of Yelm. An ancient practice\n"+
      "that turns chaotic flesh into a protective shell.\n");
   set_light(1);
   set_ac(2);
   set_type("boots");
   set_weight(1);
   set_value(12000);
}
