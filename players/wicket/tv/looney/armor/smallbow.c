inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("bow");
   set_alias("small bow");
   set_short("A Small "+MAG+"Fancy Bow"+NORM+"");
   set_long(
      "A small fancy yet adorable bow that is very small. It is very cute and stylish.\n"
   );
   set_ac(1);
   set_type("helmet");
   set_weight(1);
   set_value(500);
}