inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("yellow shirt");
   set_short("A "+HIY+"Small T"+NORM+"-"+HIY+"shirt"+NORM+"");
   set_long(
      "A small what yellow T-shirt with a B on the sleeve. \n"
   );
   set_ac(1);  /* Changed from 2 to 1 - Rumplemintz */
   set_type("chest");
   set_weight(1);
   set_value(1000);
}
