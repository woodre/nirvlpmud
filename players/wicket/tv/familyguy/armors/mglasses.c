inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("glasses");
   set_alias("nerdy glasses");
   set_short("A Pair of"+HIM+" Nerdy Glasses"+NORM+"");
   set_long(
      "A pair of nerdy coke bottle glasses, they are very clean and look very ugly.\n"
   );
   set_ac(1);  /* Changed from 2 to 1 - Rumplemintz */
   set_type("helmet");
   set_weight(1);
   set_value(1000);
}
