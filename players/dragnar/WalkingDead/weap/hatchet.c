inherit "obj/weapon";

#include <ansi.h>
#include "../defs.h"

reset(arg) {
    ::reset(arg);
  if(arg) return;

  set_name("hatchet");
  set_class(16);
  set_weight(2);
  set_value(1500);
  set_type("axe");
  set_alias("axe");
  set_alt_name("steel hatchet");
  set_short("Steel Hatchet");
  set_long("A mid length hatchet with a wooden handle and a sharpened steel axe\n\
head. This weapon is perfect for quietly dispatching walkers at close range. \n");
  SetMultipleIds( ({ "steel hatchet", "walkerobj" }) );

  set_params("physical",2);
}

query_wear() {
  return 1;
}

weapon_breaks() {
  return 1;
}

query_walker_value() { return TIER_2_VALUE + random ( TIER_2_RAND ); }
