inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("filbert shirt");
   set_short("A "+HIY+"Polo Shirt"+NORM);
   set_long(
      "a nice and comofortable polo shirt with the initial \"F\" on the pocket.\n"
   );
   set_ac(1);
   set_type("chest");
   set_weight(1);
   set_value(650);
}
