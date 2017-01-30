inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>


reset(arg) {
   set_name("old robe");
   set_alias("robe");
   set_short(RED+"Dusty Robe"+NORM);
   set_long(
      "An old dusty robe that can be tied around the waist. This\n"+
      "belonged to Master Splinter and might be handy to provide some\n"+
      "protection and resist damage.\n");
   set_ac(4);
   set_type("armor");
   set_weight(2);
   set_res(10);
   set_value(12000);
}
