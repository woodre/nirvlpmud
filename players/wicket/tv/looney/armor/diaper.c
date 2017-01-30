inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("diaper");
   set_alias("small diaper");
   set_short("A Small"+HIW+" Cloth Diaper"+NORM+"");
   set_long(
      "A small cloth diaper with a clothes pin, it smells very foul.\n"
   );
   set_ac(1);
   set_type("pants");
   set_weight(1);
   set_value(700);
  }