inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("spandex");
   set_alias("hero spandex");
   set_short("A Pair of"+HIR+" Tight Spandex"+NORM+" with a "+HIY+"Lightning Icon"+NORM+"");
   set_long(
      "A tight pair of hero spandex that are bright red. A Lightning symbol is on the chest\n"
   );
   set_ac(3);
   set_type("armor");
   set_weight(2);
   set_value(1100);
  }