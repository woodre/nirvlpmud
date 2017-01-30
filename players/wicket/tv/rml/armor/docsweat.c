inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("sweater");
   set_alias("doc sweater");
   set_short("A small "+MAG+"knitted sweater with long sleeves"+NORM);
   set_long(
      "a small knitted sweater with long sleeves that is very comfortable and warm.\n"
   );
   set_ac(2);
   set_type("armor");
   set_weight(1);
   set_value(700);
}
