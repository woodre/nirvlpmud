#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=0;
     spell_level=10;
     casting_time=4;
     duration=0;
     spell_cost=250;
     id_name="death";
     spell_name="Word of Death";
     spell_desc="The utterance of the Word causes the very life force of " +
       "your opponent to flee his body. It will do 50-500 points of damage " +
       "to the target, taking 4 rounds of preparation.\n\n" +
       "Cost: 250 spell points\n" +
       "Type: necromancy\n" +
       "Format: cast death (<target>)\n";
     properties=({ "living_target", "attack_spell" });
     spell_type="necromancy";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write("You fold your hands and meditate.\n");
  ssay(me, NAME + " folds his hands and appears lost in concentration.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  int exp;
  if(targ[0]!=me && (!targ[0] || !present(targ[0], environment(me)))) {
    write("That person is no longer here.\n");
    ssay(me, NAME + " stops concentrating and scowls.\n");
    return 1;
  }
  if(targ[0]==me) {
    write(format("You gasp for air and just manage to gather enough energy " +
     "to abort the spell and save your life.\n"));
    ssay(me, NAME + " turns pale and quivers, gasping for air.\n");
    return 1;
  }
  if(!me->valid_attack(targ[0])) {
    ssay(me, NAME + " stops concentrating and scowls.\n");
    return 1;
  }
  ssay(targ[0], NAME + " utters something and " + WHO + " turns pale and " +
   "collapses, gasping for air.\n");
  tell_object(targ[0], format(NAME + " utters something and you collapse to " +
   "the ground gasping for air. Blackness swirls before you.\n"));
  if(!targ[0]->query_attack())
    targ[0]->attacked_by(me);
  exp=(int)targ[0]->hit_player((random(10) + 1) * 50);
  me->add_exp(exp);
  return 1;
}

string casting_message(object *targ, object caster, int round) {
  string *mess;
  mess=({ caster->query_name() + " begins chanting.\n",
   "The air grows very cold.\n", "A strange, white glow surrounds " +
   WHO + ".\n" });
  return mess[round -1];
}
