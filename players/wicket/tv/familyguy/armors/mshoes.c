inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shoes");
   set_alias("skater shoes");
   set_short("A pair of "+HIK+" Skater Shoes"+NORM+"");
   set_long(
      "A nice pair of skater shoes that are very well worn out.\n"
   );
   set_ac(1);  /* Changed from 2 to 1 - Rumplemintz */
   set_type("boots");
   set_weight(1);
   set_value(1000);
}
