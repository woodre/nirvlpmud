#include "/players/khrell/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("shield");
   set_alias("shield");
   set_short("A goblin shield");
   set_long(
      "This is a battered wooden shield, commonly in poor condition.\n");
   
   set_ac(1);
   set_type("shield"); 
   set_weight(1);
   set_value(75);
}
