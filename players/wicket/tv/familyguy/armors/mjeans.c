inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("jeans");
   set_alias("blue jeans");
   set_short("A pair of "+BLU+" Cotton Blue Jeans"+NORM+"");
   set_long(
      "A soft pair of cotton blue jeans that are a comfortable fit.\n"
   );
   set_ac(1);  /* Changed from 2 to 1 - Rumplemintz */
   set_type("pants");
   set_weight(1);
   set_value(1000);
}
