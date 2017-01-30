#include "/players/puppy/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("gloves");
   set_alias("armor");
   set_short("A pair of work gloves");
   set_long(
      "From picking up these work gloves, one can tell that they have been\n"+
      "put to good use.  The dirt stains and blackish color prove this.\n");
   
   set_ac(1);
   set_type("ring");
   set_weight(1);
   set_value(45);
}
