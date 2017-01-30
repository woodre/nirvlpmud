#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=50;
     spell_level=4;
     casting_time=1;
     duration=600;
     spell_cost=80;
     id_name="shield";
     spell_name="Shield";
     spell_desc="This spell surrounds you with a field of magical energy. It " +
      "will deflect a portion of the damage directed at you, increasing " +
      "with level. The effect is not cumulative with \"Armor.\"\n\n" +
      "Cost: 80 spell points\n" +
      "Type: conjuration\n" +
      "Format: cast shield\n";
     properties=({ "self_target", "living_target", "no_target" });
     spell_type="conjuration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You spin, a vortex of scintillating energy flowing around " +
   "you.\n"));
  ssay(me, NAME + " spins, a vortex of scintillating energy flowing around " +
   HIM + ".\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  int shield, level;
  if(!me->query_sorcerer()) {
    write(format("You sense an imbalance in the magical energies flowing " +
     "through you. Type \"renew.\"\n"));
    ssay(0, "The swirling energies dissipate.\n");
    return 1;
  }
  level=(int)me->query_sorcerer_level();
  if(level < 9) shield=5;
  else if(level < 13) shield=4;
  else if(level < 17) shield=3;
  else shield=2;
  me->set_shield(shield, duration);
  write(format("The swirling energies coalesce into a blue aura about " +
   "you.\n"));
  ssay(me, "The swirling energies around " + NAME + " coalesce into a blue " +
   "aura.\n");
  return 1;
}

string casting_message(object *targ, object caster, int round) {
}
