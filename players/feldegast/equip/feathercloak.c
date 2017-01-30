#include "/players/feldegast/defines.h"

inherit "/obj/armor.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("feather cloak");
  set_alias("cloak");
  set_short(HIY+"A "+HIR+"f"+HIG+"e"+HIB+"a"+HIM+"t"+
            HIY+"h"+HIR+"e"+HIG+"r"+HIB+" c"+HIM+"l"+
            HIY+"o"+HIR+"a"+HIG+"k"+NORM);
  set_long("This is an ankle length cloak made out of multi-colored feathers.\n");
  set_ac(1);
  set_type("misc");
  set_weight(1);
  set_value(150);
}


