inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shoes");
   set_alias("running shoes2");
   set_short("A pair of "+HIY+"Speedy"+HIW+" Running Shoes"+NORM+"");
   set_long(
      "A pair of speedy running shoes. They once belonged to Calamity Coyote.\n"
   );
   set_ac(1);
   set_type("boots");
   set_weight(1);
   set_value(900);
}