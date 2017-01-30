inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("hairbow");
   set_alias("ribbon hairbow");
   set_short("A "+HIM+"Dressy Hairbow"+NORM+" made of "+HIM+"Ribbon"+NORM+"");
   set_long(
      "A small dressy hair bow, its is made of a soft tied ribbon.\n"
   );
   set_ac(1);
   set_type("helmet");
   set_weight(1);
   set_value(700);
  }