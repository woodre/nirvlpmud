#define MAGEPATH "/players/feldegast/mages/"
#include "/players/feldegast/defines.h"

inherit "/players/wocket/mages/obj/page.c";

object target;

reset(arg) {
  if(arg) return;
  spell="flamesnake";
  spell_short=RED+"Flamesnake"+NORM;
  spell_desc=
"Cost:  40 sp\n\
  Another original spell from Alysius Focht's library, this spell\n\
creates a rope-like tendril of flame that wraps and clings to a\n\
foe, almost as though it were alive.\n";
  time=3;
  size=5;
  spcost=40;
  hpcost=5;
  type="sorcery";
}
check_spell(object mage, string str) {
  target=previous_object()->get_target(str);
  if(!target) {
    tell_object(mage,"Your spell fizzles.\nThere must be a target for this spell.\n");
    return 0;
  }
  if(!previous_object()->target_ok(target)) {
    tell_object(mage,"Your spell fizzles.\nThat is not a valid target.\n");
    return 0;
  }
  return 1;  
}

cast_spell(mage,str) {
  tell_object(mage,
"You utter a few short words in a guttural, long dead language and\n\
then point at "+target->query_name()+".  A long tendril of living flame circles\n\
your arm and flies out at "+target->query_objective()+"!\n");
  mage->remote_say(
mage->query_name()+" utters a few short words in a guttural, long dead\n\
language and then points at "+target->query_name()+".  A long tendril of living\n\
flame circles "+mage->query_possessive()+" arm and then flies out at "+target->query_name()+"!\n");
  mage->attacked_by(target);
  target->attacked_by(mage);
  call_out("do_damage",2+random(8), ({ target, 4 }) );
}
do_damage(arg) {
  object targ;
  int count;
  targ=arg[0];
  count=arg[1];
  targ->heal_self(-15);
  if(--count > 0 && targ)
    call_out("do_damage", random(10), ({ targ, count }) );
  else {
    tell_room(environment(targ),HIY+"The firesnake fades into ashes.\n"+NORM);
    return;
  }
  if(!random(2))
    tell_room(environment(targ),
"\t"+RED+"The flamesnake twists its way around "+target->query_name()+"'s\n\
\tbody, burning flesh as it goes.\n"+NORM);
  else
    tell_room(environment(targ),
"\t"+HIR+target->query_name()+" screams in agony as twisting tendrils\n\
\tof flame lash "+target->query_possessive()+" flesh.\n"+NORM);
}
