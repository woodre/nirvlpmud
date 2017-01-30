inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("pants");
   set_alias("dress pants");
   set_short("A Fancy Pair of"+YEL+" Dress Pants"+NORM+"");
   set_long(
      "A pair of fancy tan dress pants, they are very clean and pressed.\n"
   );
   set_ac(1);
   set_type("pants");
   set_weight(1);
   set_value(800);
  }