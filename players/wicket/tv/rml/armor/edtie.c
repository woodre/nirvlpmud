inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("tie");
   set_alias("ed tie");
   set_short("A"+HIK+" Fancy Necktie"+NORM+"");
   set_long(
      "a nice fancy necktie.\n"
   );
   set_ac(1);
   set_type("necklace");
   set_weight(1);
   set_value(1000);
  }