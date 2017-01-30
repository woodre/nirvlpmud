#include "/players/puppy/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("pants");
   set_short("A pair of golden pants");
   set_long(
      "Pants that have been mended many times.  There is a\n"+
      "golden aura around them.\n");
   
   set_ac(1);
   set_type("boots");
   set_weight(1);
   set_value(75);
}
