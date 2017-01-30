#include "/players/puppy/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("boots");
   set_alias("work boots");
   set_short("A pair of work boots");
   set_long(
      "These work boots have been used in the fields for\n"+
      "years.  It's not even clear what the original color\n"+
      "was.  One of the laces is almost ready to break.\n");
   
   set_ac(1);
   set_type("boots");
   set_weight(1);
   set_value(45);
}
