inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("glasses");
   set_alias("eye glasses");
   set_short("A Fancy Pair of"+HIW+" Eye Glasses"+NORM+"");
   set_long(
      "A pair of fancy eye glasses, they are very strong presciption lenses.\n"
   );
   set_ac(1);
   set_type("helmet");
   set_weight(1);
   set_value(800);
  }