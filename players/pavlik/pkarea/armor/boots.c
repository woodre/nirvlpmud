inherit "players/pavlik/pkarea/lib/armor";
#include "/players/pavlik/pkarea/lib/damage_types.h"

reset(arg){
  ::reset(arg);
  set_short("A pair of boots");
  set_long("A pair of boots.\n");
  set_name("Boots");
  set_ac(0);
  set_weight(2);
  set_value(330);
  set_alias("boot");
  set_arm_light(0);
  set_type("boots");
  set_protection_type(SLASH, 2);
  set_protection_type(PIERCE, 2);
  set_protection_type(BASH, 2);
}


