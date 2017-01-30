inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("shirt");
   set_alias("hawaiian shirt");
   set_short("A "+HIC+"haw"+MAG+"aii"+HIC+"an"+NORM+" Shirt");
   set_long(
      "A small Soft button up hawaiian shirt with that is a soft blue with purple triangles. .\n"
   );
   set_ac(1);
   set_type("chest");
   set_weight(1);
   set_value(1000);
}
