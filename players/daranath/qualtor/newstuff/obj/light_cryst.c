#include <ansi.h>

inherit "obj/treasure";
reset(arg) {
  if(arg) return;

set_id("gemstone");
set_alias("crystal");
set_short(HIY+"Lightning "+HIC+"crystal"+NORM);
set_long("A perfectly cut crystal, it has trapped a bit of lightning within.\n");
set_weight(1);
set_value(700+random(500));
}
