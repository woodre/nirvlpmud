inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("socks");
   set_alias("cotton socks");
   set_short("A "+HIW+"Pair"+NORM+" of "+HIW+"Soft Cotton Socks"+NORM+"");
   set_long(
      "A small pair of soft and warm cotton socks. They have a small lace around the top of the socks.\n"
   );
   set_ac(1);
   set_type("pants");
   set_weight(1);
   set_value(1000);
}