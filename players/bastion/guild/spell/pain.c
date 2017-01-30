#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=10;
     spell_level=9;
     casting_time=2;
     duration=0;
     spell_cost=125;
     id_name="pain";
     spell_name="Word of Pain";
     spell_desc="Speaking this word of power causes an enemies blood to " +
      "boil--literally. It delivers 25-250 points of damage and takes " +
      "2 rounds of preparation.\n\n" +
       "Cost: 125 spell points\n" +
      "Type: alteration\n" +
       "Format: cast pain (<target>)\n";
     properties=({ "living_target", "attack_spell" });
     spell_type="alteration";
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
    write(format("You howl in pain and barely cancel the effects of the " +
     "spell before killing yourself.\n"));
    ssay(me, NAME + " speaks and suddenly howls in pain.\n");
    return 1;
  }
  if(!me->valid_attack(targ[0])) {
    ssay(me, NAME + " stops concentrating and scowls.\n");
    return 1;
  }
  ssay(targ[0], NAME + " utters something and " + WHO + " crumples to ground " +
   "shrieking.\n");
  tell_object(targ[0], NAME + " utters something and every part of your part " +
   "of your body shrieks in pain. You crumple to the ground.\n");
  if(!targ[0]->query_attack())
    targ[0]->attacked_by(me);
  exp=(int)targ[0]->hit_player((random(10) + 1) * 25);
  me->add_exp(exp);
  return 1;
}

string casting_message(object *targ, object caster, int round) {
  string *mess;
  mess=({ "A dim red glow surrounds " + WHO + ".\n" });
  return mess[round - 1];
}
