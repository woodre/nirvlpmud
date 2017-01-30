inherit "obj/armor";
#include "/sys/lib.h"
#include <ansi.h>

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("diaper");
   set_alias("small diaper");
   set_short("A Small"+HIW+" Disposable Diaper"+NORM+"");
   set_long(
      "A small disposable diaper, it smells very foul and is soaked in urine.\n"
   );
   set_ac(1);
   set_type("pants");
   set_weight(1);
   set_value(700);
  }