inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shades");
   set_alias("slim shades");
   set_short("A Pair of"+HIK+" Fancy Slim Shades"+NORM+"");
   set_long(
      "A pair of fancy shades that sparkle when the sun hits them. They are very slim and sexy.\n"
   );
   set_ac(1);
   set_type("helmet");
   set_weight(1);
   set_value(400);
}