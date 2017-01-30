inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("pants");
   set_alias("dressy pants");
   set_short("A pair of "+HIW+"Dressy Pants"+NORM+"");
   set_long(
      "A pair of stylish dress pants, they are such the in style around town.\n"
   );
   set_ac(1);
   set_type("pants");
   set_weight(1);
   set_value(750);
  }