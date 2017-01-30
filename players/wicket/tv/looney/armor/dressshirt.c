inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("dressy shirt");
   set_short("A "+HIC+"Dressy Cute Shirt"+NORM+" with flowing sleeves");
   set_long(
      "A small white dressy shirt that have flowing sleeves. A beautiful small bow is on the neck of the shirt.\n"
   );
   set_ac(2);
   set_type("armor");
   set_weight(1);
   set_value(1000);
}