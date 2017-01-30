inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("skirt");
   set_alias("cheerleading skirt");
   set_short("A "+HIW+"Cheerleading Skirt"+NORM+"");
   set_long(
      "A small white cheerleading skirt that bounces with the movement.\n"
   );
   set_ac(1);  /* Changed from 2 to 1 - Rumplemintz */
   set_type("pants");
   set_weight(1);
   set_value(1000);
}
