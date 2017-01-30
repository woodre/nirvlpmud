#include "/players/martha/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("shoes");
   set_short("A Pair of Black Mens Shoes");
   set_long(
      "These shoes are black as night.  These casual mens dress shoes\n"+
      "are shiny, but look a little worn.\n");
   
   set_ac(2);
   set_type("boots");  
   set_weight(0);
   set_value(500);
}


