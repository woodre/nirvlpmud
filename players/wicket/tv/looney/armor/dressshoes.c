inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shoes");
   set_alias("dress shoes");
   set_short("A "+HIK+"Fancy Pair"+NORM+" of "+HIK+"Dress Shoes"+NORM+"");
   set_long(
      "A fancy pair of dress shoes, they are very clean and polished up.\n"
   );
   set_ac(1);
   set_type("boots");
   set_weight(1);
   set_value(1000);
  }