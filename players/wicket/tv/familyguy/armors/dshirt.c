inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("dress shirt");
   set_short("A Fancy"+HIW+" Button Up Dress Shirt"+NORM+"");
   set_long(
      "A soft cotton button up dress shirt, It is very light and breaths good.\n"
   );
   set_ac(1);
   set_type("chest");
   set_weight(1);
   set_value(800);
  }