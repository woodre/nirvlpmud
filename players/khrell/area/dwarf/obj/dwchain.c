#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("dwarf Chainmail");
   set_alias("chainmail");
   set_short(HIW+"Dwarfen chainmail"+NORM);
   set_long(
      "This is the long description\n");
   
   set_ac(4);
   set_type("armor");
   set_weight(2);
   set_value(1000);
}
