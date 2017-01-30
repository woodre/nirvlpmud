#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=60;
     spell_level=4;
     casting_time=1;
     duration=0;
     spell_cost=30;
     id_name="lightning";
     spell_name="Lightning";
     spell_desc="With this spell you release a bolt of electricity from " +
      "your hands to strike down a foe. It will do 6-60 points of damage.\n\n"+
      "Cost: 30 spell points\n" +
      "Type: conjuration\n" +
      "Format: cast lightning (<target>)\n";
     properties=({ "living_target", "attack_spell" });
     spell_type="conjuration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You ball your fists, static tingling your scalp.\n"));
  ssay(me, NAME + " balls " + HIS + " fists, static sparking through " +
   HIS + " hair.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  int exp;
  if(targ[0]!=me && (!targ[0] || !present(targ[0], environment(me)))) {
    write("That person is no longer here.\n");
    return 1;
  }
  if(targ[0]==me) {
    write("You succeed only in singeing your clothing.\n");
    ssay(me, NAME + " hits " + HIM + "self with a bolt of electricity, " +
     "singeing " + HIS + " clothing.\n");
    return 1;
  }
  if(!me->valid_attack(targ[0])) {
    ssay(me, NAME + " unclenches " + HIS + " fists and sighs.\n");
    return 1;
  }
  ssay(targ[0], WHO + " is struck by an arc of eletricty.\n");
  tell_object(targ[0], NAME + " strikes you with an arc of electricity!\n");
  if(!targ[0]->query_attack())
    targ[0]->attacked_by(me);
  exp=(int)targ[0]->hit_player((random(10) + 1) * 6);
  me->add_exp(exp);
     return 1;
}
