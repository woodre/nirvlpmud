#include "/players/puppy/define.h"
inherit "obj/armor";

reset(arg) {
   set_name("crown");
   set_alias("helmet");
   set_short("A golden crown");
   set_long(
      "A polished crown that you feel you might be worthy to place\n"+
      "on your head.  Only those of royalty may wear it.\n");
   
   set_ac(1);
   set_type("helmet");
   set_weight(1);
   set_value(75);
}
