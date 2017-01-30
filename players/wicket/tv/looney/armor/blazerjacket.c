inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("jacket");
   set_alias("blazer jacket");
   set_short("A "+BLU+"Fancy Blazer Jacket"+NORM+"");
   set_long(
      "A fancy blazer jacket, it is very clean and wrinkle free.\n"
   );
   set_ac(2);
   set_type("armor");
   set_weight(1);
   set_value(1000);
  }