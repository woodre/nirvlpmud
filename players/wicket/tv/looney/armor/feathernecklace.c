inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("collar");
   set_alias("collar of feathers");
   set_short("A Collar of "+HIM+"Fea"+MAG+"th"+HIM+"ers"+NORM+"");
   set_long(
      "A collar of feathers made from the ones of Concord the condor.\n"
   );
   set_ac(1);
   set_type("necklace");
   set_weight(1);
   set_value(700);
}