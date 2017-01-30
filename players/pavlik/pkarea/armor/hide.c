inherit "players/pavlik/pkarea/lib/armor";
#include "/players/pavlik/pkarea/lib/damage_types.h"

reset(arg){
  ::reset(arg);
  set_short("An animal hide");
  set_long(
  "A cured hide of some dead animal.  The hide has an awful smell to it\n"+
  "but it might also be a warm and protective garment if worn.\n");
  set_name("Animal Hide");
  set_ac(0);
  set_weight(2);
  set_value(330);
  set_alias("hide");
  set_arm_light(0);
  set_type("armor");
  set_protection_type(SLASH, 3);
  set_protection_type(PIERCE, 3);
  set_protection_type(BASH, 3);
}


