inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("aapron");
   set_alias("doc aapron");
   set_short("A small used"+HIW+" surgical protective aapron"+NORM);
   set_long(
      "a small used surgical protective aapron that has a few small stains and blood.\n"
   );
   set_ac(0);
   set_type("chest");
   set_weight(1);
   set_value(700);
}
