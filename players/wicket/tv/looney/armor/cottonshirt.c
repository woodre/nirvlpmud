inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("cotton shirt");
   set_short("A "+HIW+"Soft Cotton Shirt"+NORM+"");
   set_long(
      "A soft cotton shirt, it is very light and comfortable.\n"
   );
   set_ac(1);
   set_type("chest");
   set_weight(1);
   set_value(700);
  }