inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("pink shirt");
   set_short("A Small"+MAG+" Pink "+NORM+"Shirt");
   set_long(
      "A small pink shirt that Babs bunny wears. it is a part of her cute outfit.\n"
   );
   set_ac(2);
   set_type("armor");
   set_weight(3);
   set_value(900);
}