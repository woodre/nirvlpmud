inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("red hat");
   set_short("A "+HIR+"Small T"+NORM+"-"+HIR+"shirt"+NORM+"");
   set_long(
      "A small red t-shirt made of soft fabric. It has a letter B on the sleeve.\n"
   );
   set_ac(1);
   set_type("chest");
   set_weight(1);
   set_value(600);
}