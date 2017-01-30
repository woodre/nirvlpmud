inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("dress");
   set_alias("bev dress");
   set_short("A"+MAG+" Flowing evening dress"+NORM+"");
   set_long(
      "a nice flowing evening dress that just flows with every movement.\n"
   );
   set_ac(2);
   set_type("armor");
   set_weight(1);
   set_value(1100);
  }