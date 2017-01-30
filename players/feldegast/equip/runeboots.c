#include "defs.h"

inherit RUNE_ARMOR;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("boots");
  set_alias("greaves");
  set_short(HIB+"Rune Boots"+NORM);
  set_long(
    "These greaves have been forged from the finest steel and etched with\n"+
    "mystical runes of great power.  This appears to be a single piece\n"+
    "of a set of armor.\n"
  );
  set_type("boots");
  set_weight(2);
  set_ac(1);
  set_value(1800);
}

int do_special(object owner) {
  if(!activated && !random(12)) {
    tell_object(owner, CYN+"The runes on your boots flash protectively!\n");
    return 2;
  }
  if(activated && !random(10)) {
    tell_object(owner, CYN+"The runes on your boots flash!\n"+NORM+
                       GRN+"  You swiftly dodge the blow!\n"+NORM);
    return 2+random(3); /* 2-4 */
  }
}
