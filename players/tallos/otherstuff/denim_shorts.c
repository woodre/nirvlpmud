#include "../define.h"
inherit ARMOUR;

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_short("Shamanic "+BLU+"boxer shorts"+NORM);
   set_id("shorts");
   set_alias("boxer shorts");
   set_type("underwear");
   set_ac(2);
   set_long(
      "Tattered boxer shorts that seem to have some property\n"+
      " to them that makes them offer a bit more protection.\n"+
      " They *WERE* from a shaman, of course.\n");
}

do_special(owner) {
   if(!random(8)) {
      tell_object(USER,
         " . .. the cotton seems to "+BLU+"f  ad e"+NORM+" from reality for a split-second.\n"+
         "The shorts remorph themselves.\n");
      return 1; }
}
