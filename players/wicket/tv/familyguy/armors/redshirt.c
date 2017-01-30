inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("cotton shirt");
   set_short("A Small"+HIR+" Cotton Shirt"+NORM+"");
   set_long(
      "A small cotton shirt, It very soft and warm.\n"
   );
   set_ac(1);
   set_type("chest");
   set_weight(1);
   set_value(1400);
  }