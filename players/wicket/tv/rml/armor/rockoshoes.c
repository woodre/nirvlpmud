inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shoes");
   set_alias("orange shoes");
   set_short("A pair of"+HIY+" running shoes"+NORM+"");
   set_long(
      "a nice pair of comofortable clean sport shoes.\n"
   );
   set_ac(1);
   set_type("boots");
   set_weight(1);
   set_value(900);
  }