inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("skirt");
   set_alias("yellow skirt");
   set_short("A "+HIY+"Cheerleader"+NORM+" Skirt");
   set_long(
      "A cheerleading skirt that Babs bunny use to wear.\n"
   );
   set_ac(1);
   set_type("pants");
   set_weight(3);
   set_value(900);
}