inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("collar");
   set_alias("spunky collar");
   set_short("A small used"+HIR+" dog collar"+NORM);
   set_long(
      "a small little dog collar with a plate thats has the name spunky engraved on it.\n"
   );
   set_ac(0);
   set_type("necklace");
   set_weight(1);
   set_value(700);
}
