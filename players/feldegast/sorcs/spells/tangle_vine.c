#include "/players/feldegast/defines.h"
#define PATH "/players/wocket/mages/"
inherit "/players/wocket/mages/obj/page";

object attacker;

reset(arg) {
  if(arg) return;
  spell="tangle vine";
  spell_short=HIG+"Tangle Vine"+NORM;
  spell_desc=
"Cost: 50 sps\n\
  This is one of the few summoning spells that does not require\n\
a summoning circle to use.  While a summoning circle is often\n\
necessarry to bind a creature to the mage's will, a tangle vine\n\
has no will and it is only necessary to nudge it in the right\n\
direction upon summoning.\n";
  time=1;
  size=3;
  spcost=50;
  hpcost=5;
  type="summon";
}

int check_spell(object mage, string arg) {
  
  attacker=(object)previous_object()->get_target(arg);
  if(!attacker) {
    write("You must have a target for this spell.\n");
    return 0;
  }

  if(!previous_object()->target_ok(attacker)) {
    tell_object(mage,"You must have a valid target for this spell.\n");
    return 0;
  }
  return 1;
}

void cast_spell(object mage, string arg) {
  object vine;
  tell_room(environment(attacker),
"A "+HIG+"tangle vine"+NORM+" sprouts beneath "+attacker->query_name()+" and wraps "+attacker->query_objective()+"\n"+
"in its tendrils.\n");
  vine=clone_object(PATH+"mon/tangle_vine");
  move_object(vine,environment(attacker));
  attacker->attacked_by(vine);
  vine->attacked_by(attacker);
  attacker->attack_object(vine);
}

