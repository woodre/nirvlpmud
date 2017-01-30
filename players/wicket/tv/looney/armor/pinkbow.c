inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("bow");
   set_alias("pink bow");
   set_short("A Cute "+MAG+"Pink Bow"+NORM+"");
   set_long(
      "A small  pink bow that is very cute. It's a great hair accessory.\n"
   );
   set_ac(1);  /* Changed from 2 to 1 - Rumplemintz */
   set_type("helmet");
   set_weight(3);
   set_value(900);
}
