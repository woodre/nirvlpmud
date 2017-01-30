/* 
Flame Whip

Attack spell, uses spell_object, causes target to attack
spellcaster.  (yes, I did that on purpose).
Damage: 10+random(30)
Cost: 20 sps
*/
#define MAGEPATH "/players/feldegast/mages/"
#include "/players/feldegast/defines.h"

inherit "/players/wocket/mages/obj/page.c";

object target;

reset(arg) {
  if(arg) return;
  spell="flame whip";
  spell_short=HIR+"Flame Whip"+NORM;
  spell_desc=
"Cost:  20 sp\n\
  A demented tool of painful death, the flame whip is almost\n\
considered taboo by some magicians, due to the horrific tales\n\
of how Alysius Focht used it to avenge the murder of his wife.\n\
It is also said that thenceforth, the flame whip sprang forth\n\
automatically whenever the great pyromancer became enraged.\n";
  time=1;
  size=2;
  spcost=20;
  hpcost=0;
  type="summon";
}
check_spell(object mage, string str) {
  target=previous_object()->get_target(str);
  if(!target) {
    tell_object(mage,"There must be a target for this spell.\n");
    return 0;
  }
  if(!previous_object()->target_ok(target)) {
    tell_object(mage,"That is not a valid target.\n");
    return 0;
  }
  return 1;  
}
cast_spell(object mage, string str) {
  target->attacked_by(mage);
  mage->attacked_by(target);
  tell_object(mage,"A whip of living flame springs from the palm of your hand at your command!\n");
  mage->spell_object(target,"flame whip",10+random(30),5,
    "You lash "+target->query_name()+" with your "+HIR+"flame whip"+NORM+"!\n",
    mage->query_name()+" lashes you with a "+HIR+"flame whip"+NORM+"!\n",
    "");
  tell_room(environment(mage),
    mage->query_name()+" lashes "+target->query_name()+" with a "+HIR+"flame whip"+NORM+"!\n",
    ({ mage, target }));
}



