inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("pants");
   set_alias("blazer pants");
   set_short("A Pair of"+BLU+" Fancy Blazer Pants"+NORM+"");
   set_long(
      "A pair of fancy blazer pants, they is very clean and wrinkle free.\n"
   );
   set_ac(1);  /* Changed from 2 to 1 - Rumplemintz */
   set_type("pants");
   set_weight(1);
   set_value(1000);
}
