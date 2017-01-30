inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("sneakers");
   set_alias("stylish sneakers");
   set_short("A Pair of "+HIW+"Sty"+HIK+"lish"+HIW+" Snea"+HIK+"kers"+NORM+"");
   set_long(
      "A fancy pair of stylish sneakers. They seem to be very clean and in good condition.\n"
   );
   set_ac(1);
   set_type("boots");
   set_weight(1);
   set_value(720);
  }