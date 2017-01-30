inherit "players/pavlik/pkarea/lib/armor";
#include "/players/pavlik/pkarea/lib/damage_types.h"

reset(arg){
  ::reset(arg);
  set_short("An Amulet");
  set_long("An Amulet.\n");
  set_name("amulet");
  set_ac(0);
  set_weight(2);
  set_value(330);
  set_alias("amulet");
  set_arm_light(0);
  set_type("amulet");
  set_protection_type(SLASH, 1);
  set_protection_type(PIERCE, 1);
  set_protection_type(BASH, 1);
}


