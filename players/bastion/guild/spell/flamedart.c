#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=90;
     spell_level=1;
     casting_time=1;
     duration=0;
     spell_cost=10;
     id_name="flamedart";
     spell_name="Flamedart";
     spell_desc="With this spell you create a small ball of flame which " +
       "shoots forth from your hands to strike your enemy. It will do " +
       "from 5-20 points of damage to the selected target.\n\n" +
       "Cost: 10 spell points\n" +
      "Type: conjuration\n" +
       "Format: cast flamedart (<target>)\n";
     properties=({ "living_target", "attack_spell" });
     spell_type="conjuration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write("You cast flamedart at " + WHO + ".\n");
  ssay(me, NAME + " mutters something in harsh syllables.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  int exp;
  if(targ[0]!=me && (!targ[0] || !present(targ[0], environment(me)))) {
    write("That person is no longer here.\n");
    ssay(me, NAME + " stops muttering and looks frustrated.\n");
    return 1;
  }
  if(targ[0]==me) {
    write("You succeed only in singeing your clothing.\n");
    ssay(me, NAME + " hits " + HIM + "self with a small ball of flame, " +
     "singeing " + HIS + " clothing.\n");
    return 1;
  }
  if(!me->valid_attack(targ[0])) {
    ssay(me, NAME + " stops muttering and looks frustrated.\n");
    return 1;
  }
  ssay(targ[0], WHO + " is hit by a small ball of flame.\n");
  tell_object(targ[0], NAME + " hits you with a small ball of flame!\n");
  if(!targ[0]->query_attack())
    targ[0]->attacked_by(me);
  exp=(int)targ[0]->hit_player((random(4) + 1) * 5);
  me->add_exp(exp);
     return 1;
}
