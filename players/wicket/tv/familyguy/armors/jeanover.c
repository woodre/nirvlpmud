inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("overalls");
   set_alias("jean overalls");
   set_short("A Small"+HIC+" Jean Overalls"+NORM+"");
   set_long(
      "A pair of overalls made of jean material, It has small hooks and buttons on the chest to connect the straps.\n"
   );
   set_ac(1);
   set_type("armor");
   set_weight(2);
   set_value(1400);
  }