inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shoes");
   set_alias("running shoes");
   set_short("A pair of "+HIY+"Lightning"+HIR+" Fast"+HIW+" Running Shoes"+NORM+"");
   set_long(
      "A pair of lightning fast running shoes. They once belonged to Little Beeper the Roadrunner.\n"
   );
   set_ac(1);
   set_type("boots");
   set_weight(1);
   set_value(900);
}
