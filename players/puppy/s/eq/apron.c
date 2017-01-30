#include "/players/puppy/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("apron");
   set_alias("shield");
   set_short("An apron");
   set_long(
      "A stained apron that helps protect Painter Smurf from being\n"+ 
      "the messiest Smurf of them all.\n");
   
   set_ac(1);
   set_type("shield");
   set_weight(1);
   set_value(50);
}
