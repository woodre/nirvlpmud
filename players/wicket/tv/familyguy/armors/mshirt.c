inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("pink shirt");
   set_short("A short sleeve"+HIM+" cotton shirt"+NORM+"");
   set_long(
      "A soft cotton shirt that is very comofortable to wear.\n"
   );
   set_ac(1);  /* Changed from 2 to 1 - Rumplemintz */
   set_type("chest");
   set_weight(1);
   set_value(1000);
}
