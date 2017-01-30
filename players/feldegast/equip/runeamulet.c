#include "defs.h"

inherit RUNE_ARMOR;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("rune amulet");
  set_alias("amulet");
  set_short(HIB+"Rune Amulet"+NORM);
  set_long(
    "A magnificent blue gemstone is set into the center of a silver\n"+
    "circle that has been etched with mystical runes of great power.\n"+
    "This appears to be a single piece of a set of armor.\n"
  );
  set_type("amulet");
  set_weight(1);
  set_ac(1);
  set_value(1800);
}

int do_special(object owner) {
  if(!activated && !random(12)) {
    tell_object(owner, CYN+"The runes on your amulet flash protectively!\n");
    return 3;
  }
  if(activated && !random(10)) {
    tell_object(owner, CYN+"The runes on your amulet flash!\n"+NORM+
                       "You are imbued with mystic energy.\n");
    owner->add_spell_point(random(5));
    return 1+random(3); /* 1-3 */
  }
}    