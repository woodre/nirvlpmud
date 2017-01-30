inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("pink shirt");
   set_short("A Cotton"+MAG+" Pink "+NORM+"Shirt"+NORM+"");
   set_long(
      "A small cotton pink shirt that is very comfortable. It's very cute and stylish.\n"
   );
   set_ac(2);
   set_type("armor");
   set_weight(3);
   set_value(900);
}