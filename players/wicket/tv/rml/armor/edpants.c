inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("pants");
   set_alias("ed pants");
   set_short("A"+HIK+" Fancy dress pants"+NORM+"");
   set_long(
      "a nice pair of fancy dress pants.\n"
   );
   set_ac(1);
   set_type("pants");
   set_weight(1);
   set_value(1000);
  }