inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("hat");
   set_alias("propeller hat");
   set_short("A "+HIY+"Propeller"+HIM+" Hat"+NORM+"");
   set_long(
      "A small hat with a propeller attached to the top of it. The propeller spins by itself.\n"
   );
   set_ac(1);
   set_type("helmet");
   set_weight(1);
   set_value(400);
}