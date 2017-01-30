#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=40;
     spell_level=6;
     casting_time=1;
     duration=0;
     spell_cost=40; /* per critter */
     id_name="firestorm";
     spell_name="Firestorm";
     spell_desc="With this spell you create a seething mass of flame to " +
      "ignite your enemies. It will cause 8-96 points of damage to all " +
      "affected.\n\n" +
       "Cost: 120 spell points + 40 for every target over 3\n" +
      "Type: conjuration\n" +
       "Format: cast firestorm (<target>)\n";
     properties=({ "living_target", "attack_spell", "area_effect" });
     spell_type="conjuration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You raise you hands in the air and incant firestorm. The " +
   "smell of brimstone fills the air.\n"));
  ssay(me, NAME + " raises his hands in the air and chants something. The " +
   "smell of brimstone fills the air.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  int i, exp;
  if(targ[0]!=me && !present(targ[0], environment(me))) {
    write("That person is no longer here.\n");
    ssay(0, "The sulfurous smell fades.\n");
    return 1;
  }
  if(targ[0]==me) {
    write(format("You burn your eyebrows off, not to mention your " +
     "clothing.\n"));
    ssay(me, "A cloud of flame bursts around " + NAME + ". When the smoke " +
     "clears " + NAME + " looks rather singed and naked.\n");
    return 1;
  }
  if(!me->valid_attack(targ[0])) {
    ssay(0, "The sulfurous smell fades.\n");
    return 1;
  }
  ssay(0, "The air suddenly bursts with flames!\n");
  for(i=0; i < sizeof(targ); i++) {
    if(targ[i] && targ[i]!=me && ((object)targ[i]->query_attack()==me ||
     !targ[i]->is_player()) && !targ[i]->id("guild_pet")) {
      tell_object(targ[i], format("You are burned in the blast.\n"));
      ssay(targ[i], targ[i]->query_name() + " is burned in the blast.\n");
      if(!targ[i]->query_attack())
        targ[i]->attacked_by(me);
      exp=(int)targ[i]->hit_player((random(12) + 1) * 8);
      me->add_exp(exp);
    }
    else  if(targ[i]!=me) {
      tell_object(targ[i], format("You dive out of the way of the " +
       "explosion.\n"));
      ssay(targ[i], targ[i]->query_name() + " dives out of the way of the " +
       "explosion.\n");
    }
  }
  return 1;
}
