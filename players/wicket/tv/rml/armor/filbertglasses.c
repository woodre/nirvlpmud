inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("glasses");
   set_alias("filbert glasses");
   set_short("A pair of "+HIB+"Nerdy Glasses"+NORM);
   set_long(
      "A pair of nerdy glasses with the name Filbert on the Earpiece.\n"
   );
   set_ac(1);
   set_type("helmet");
   set_weight(1);
   set_value(650);
}
