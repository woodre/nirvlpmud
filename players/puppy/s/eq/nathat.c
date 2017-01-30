#include "/players/puppy/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("hat");
   set_alias("straw hat");
   set_short("A straw hat");
   set_long(
      "Many strands of straw woven together make this a very light\n"+
      "piece of armor.  It seems more of a fashion statement than\n"+
      "something that could protect you.\n");
   
   set_ac(1);
   set_type("helmet");
   set_weight(1);
   set_value(25);
}
