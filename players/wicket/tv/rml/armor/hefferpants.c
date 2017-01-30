inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("pants");
   set_alias("red pants");
   set_short("A pair of "+HIR+"XXXXL Pants"+NORM+" with "+HIR+"suspenders"+NORM+"");
   set_long(
      "A huge pair of pants with a tag inside with the name Heffer Wolfe. The pants are stained badly.\n"
   );
   set_ac(0);
   set_type("pants");
   set_weight(1);
   set_value(1000);
}
