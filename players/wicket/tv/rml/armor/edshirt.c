inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("ed shirt");
   set_short("A"+HIW+" Fancy buttonup dress shirt"+NORM+"");
   set_long(
      "a nice fancy button up dress shirt.\n"
   );
   set_ac(1);
   set_type("armor");
   set_weight(1);
   set_value(1000);
  }