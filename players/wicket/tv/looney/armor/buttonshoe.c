inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shoes");
   set_alias("leather button shoes");
   set_short("A Pair of"+HIK+" Leather Button Shoes"+NORM+"");
   set_long(
      "A small pair of leather button shoes. They are very shiny and in nice condition.\n"
   );
   set_ac(1);
   set_type("boots");
   set_weight(1);
   set_value(1000);
}