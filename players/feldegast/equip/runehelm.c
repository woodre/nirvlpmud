#include "defs.h"

inherit RUNE_ARMOR;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("helm");
  set_alias("helmet");
  set_short(HIB+"Rune Helm"+NORM);
  set_long(
    "This helm has been forged from the finest steel and etched with\n"+
    "mystical runes of great power.  This appears to be a single piece\n"+
    "of a set of armor.\n"
  );
  set_type("helmet");
  set_weight(2);
  set_ac(1);
  set_value(1800);
}

int do_special(object owner) {
  if(!activated && !random(12)) {
    tell_object(owner, CYN+"The runes on your helmet flash protectively!\n");
    return 3;
  }
  if(activated && !random(10)) {
    tell_object(owner, CYN+"The runes on your helmet flash!\n"+NORM+
                       "Your concentration is sharpened.\n");
    owner->add_spell_point(random(5));
    return 1+random(3); /* 1-3 */
  }
}
