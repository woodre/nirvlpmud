#include "/players/puppy/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("cape");
   set_alias("armor");
   set_short("A flowing cape");
   set_long(
      "This cape is made almost entirely of velvet.  The edges of\n"+
      "it have been hand-stitched.  You wonder if you are worthy\n"+ 
      "enough to wear this.\n");
   
   set_ac(1);
   set_type("misc");
   set_weight(1);
   set_value(25);
}
