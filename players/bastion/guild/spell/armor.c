#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=90;
     spell_level=1;
     casting_time=1;
     duration=600;
     spell_cost=50;
     id_name="armor";
     spell_name="Armor";
     spell_desc="This spell causes your skin to toughen, protecting you from " +
      "harm. The effect lasts only for a few minutes though, your new armor " +
      "class improving with level (to a maximum to 9).\n\n" +
      "Cost: 50 spell points\n" +
      "Type: alteration\n" +
      "Format: cast armor\n";
     properties=({ "self_target", "living_target", "no_target" });
     spell_type="alteration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You take out a small lump of clay and roll it into a ball.\n"));
  ssay(me, NAME + " takes out a small lump of clay and rolls it into a ball" +
   ".\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  int armor;
  if(!me->query_sorcerer()) {
    write(format("You sense an imbalance in the magical energies flowing " +
     "through you. Type \"renew.\"\n"));
    ssay(me, NAME + " sighs and puts the clay away.\n");
    return 1;
  }
  armor=(int)me->query_sorcerer_level() / 2 + 2;
  if(armor > 9) armor=9;
  me->set_armor(armor, duration);
  write(format("The clay warms and hardens. You feel your skin toughen.\n"));
  ssay(me, "The clay in " + NAME + "'s hands grows white and hardens.\n");
  return 1;
}

string casting_message(object *targ, object caster, int round) {
}
