#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=70;
     spell_level=3;
     casting_time=1;
     duration=0;
     spell_cost=20;
     id_name="feigndeath";
     spell_name="Feign Death";
     spell_desc="This spells causes your spirit to flee your body as in " +
      "death. For all intents and purposes you will be dead, however you " +
      "will not suffer any of the consequences of dying.\n\n" +
      "Cost: 20 spell points\n" +
      "Type: necromancy\n" +
      "Format: cast feigndeath\n";
     properties=({ "self_target", "no_attack", "no_target", "living_target" });
     spell_type="necromancy";
}


int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You raise your arms and begin the mantra of death.\n"));
  ssay(me, NAME + " raises " + HIS + " arms and begins chanting.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  ssay(me, NAME + " collapses.\n");
  me->second_life();
}

string casting_message(object *targ, object caster, int round) {
}
