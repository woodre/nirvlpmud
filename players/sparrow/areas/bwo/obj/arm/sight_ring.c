#include "/sys/ansi.h"
inherit "/obj/armor";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("eyes");
  set_alias("circlet");
  set_short(HIK+"Eyes of the "+HIW+"B"+HIK+"lack "+HIW+"W"+HIK+"illow"+NORM);
   set_long("This appears to be a simple silver circlet inset with an onyx\n"+
            "stone that hangs slightly lower than the band. When worn the\n"+
			"stone will rest just above and between the wearer's eyes.\n");
  set_ac(1);
  set_type("helmet");
  set_weight(1);
  set_value(2750);
}

status id(string str) {
  return (status)::id(str) ||
  str == "dark_sight_object";
}