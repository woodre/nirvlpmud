#if 0 /* Rumplemintz */
#include "/open/ansi.h"
#else
#include <ansi.h>
#endif
inherit "obj/armor";

reset(arg){
   ::reset(arg);
    set_short(HIY+"H"+NORM+"oly "+HIY+"M"+NORM+"itre");
   set_long("The holy mitre usually worn by the Bishop in important Catholic Ceremonies ,\n"+
      "it can protect your head while u fight.\n");
   set_ac(1);
  set_params("other|good",0,10,0);
  set_params("other|evil",0,10,0);
   set_weight(1);
   set_value(500);
   set_alias("helmet");
   set_name("mitre");
   set_type("helmet");
}
