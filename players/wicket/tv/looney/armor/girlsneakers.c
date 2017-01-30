inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("sneakers");
   set_alias("girly sneakers");
   set_short("A Pair of"+HIM+" Girly Sneakers"+NORM+"");
   set_long(
      "A small pair of girly sneakers, they look really comfortable and clean.\n"
   );
   set_ac(1);
   set_type("boots");
   set_weight(1);
   set_value(725);
  }