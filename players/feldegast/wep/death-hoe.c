#include "defs.h"

inherit "/obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_type("polearm");
  set_class(17);
  set_name("hoe");
  set_alias("death-hoe");
  set_short(BOLD+BLK+"Hoe of Death and Destruction"+NORM);
  set_weight(3);
  set_value(500);
  set_long(
    "This once common farming implement has been transformed into an instrument\n"+
    "of death and destruction.  The long wooden handle glows with a strong aura\n"+
    "magic and the razor sharp head crackles with death energy.\n"
  );
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  string msg;
  if(!random(4)) {
    switch(random(4)) {
      case 0: msg="\n"+TPN+" sweeps the death-hoe about in an arc!\n\n";
              break;
      case 1: msg="\n"+attacker->query_name()+" screams in agony as "+attacker->query_pronoun()+" feels the death-hoe's wrath!\n\n";
              break;
    case 2: msg="\n"+BOLD+BLK+TPN+" twirls the death-hoe about "+TP->query_possessive()+" body!\n\n"+NORM;
              break;
      case 3: msg="\n\n"+short_desc+" crackles with malignant power!\n\n";
              break;
    }
    tell_room(environment(TP),msg);
    return random(4);
  }
}
