inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("overalls");
   set_alias("blue overalls");
   set_short("A pair of "+BLU+"Overalls"+NORM+" With "+HIK+"Button straps"+NORM+"");
   set_long(
      "A pair of overalls, the straps come over the shoulder and hook back to the chest with a button strap.\n"
   );
   set_ac(1); /* Changed from 2 to 1 - Rumplemintz */
   set_type("pants");
   set_weight(1);
   set_value(100);
}
