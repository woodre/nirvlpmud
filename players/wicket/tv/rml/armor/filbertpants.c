inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("pants");
   set_alias("filbert pants");
   set_short("A pair of"+YEL+" khaki pants "+NORM+"");
   set_long(
      "a nice pair of khaki pants that fit amazingly.\n"
   );
   set_ac(1);
   set_type("pants");
   set_weight(1);
   set_value(1000);
  }