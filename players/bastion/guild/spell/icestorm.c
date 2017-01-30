#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=50;
     spell_level=5;
     casting_time=1;
     duration=0;
     spell_cost=25; /* per critter */
     id_name="icestorm";
     spell_name="Icestorm";
     spell_desc="This spell creates a flurry of driving hail (even " +
      "indoors!) to crush your opponents. It will hit all affected " +
      "creatures for 6-60 points of damage.\n\n" +
       "Cost: 75 spell points + 25 for every target over 3\n" +
      "Type: conjuration\n" +
       "Format: cast icestorm (<target>)\n";
     properties=({ "living_target", "attack_spell", "area_effect" });
     spell_type="conjuration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write("You begin to chant, frost forming in your breath.\n");
  ssay(me, format(NAME + " begins chanting, frost forming in his breath. " +
   "You shiver.\n"));
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  int i, exp;
  if(targ[0]!=me && !present(targ[0], environment(me))) {
    write("That person is no longer here.\n");
    ssay(me, NAME + " stops chanting and the air warms again.\n");
    return 1;
  }
  if(targ[0]==me) {
    write(format("You dive out of the way as chunks of ice fall to crush " +
     "you!\n"));
    ssay(me, NAME + " dives out of the way as chunks of ice fall to crush " +
     HIM + ".\n");
    return 1;
  }
  if(!me->valid_attack(targ[0])) {
    ssay(me, (NAME + " stops chanting and the air warms again.\n"));
    return 1;
  }
  ssay(0, "Suddenly, chunks out ice begin to spew down out of the frozen " +
   "air.\n");
  for(i=0; i < sizeof(targ); i++) {
    if(targ[i] && targ[i]!=me && ((object)targ[i]->query_attack()==me ||
     !targ[i]->is_player()) && !targ[i]->id("guild_pet")) {
      tell_object(targ[i], format("You are pelted by the ice.\n"));
      ssay(targ[i], targ[i]->query_name() + " is pelted by the ice.\n");
      if(!targ[i]->query_attack())
        targ[i]->attacked_by(me);
      exp=(int)targ[i]->hit_player((random(10) + 1) * 6);
      me->add_exp(exp);
    }
    else  if(targ[i]!=me) {
      tell_object(targ[i], format("You dive out of the way of the driving " +
       "hail.\n"));
      ssay(targ[i], targ[i]->query_name() + " dives out of the way of the " +
       "driving hail.\n");
    }
  }
  return 1;
}
