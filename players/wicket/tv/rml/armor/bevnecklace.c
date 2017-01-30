inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("necklace");
   set_alias("bev necklace");
   set_short("A"+HIW+" Fancy pearl necklace"+NORM+"");
   set_long(
      "a fancy pearl necklace made of beautiful flawless pearls.\n"
   );
   set_ac(1);
   set_type("necklace");
   set_weight(1);
   set_value(1100);
  }