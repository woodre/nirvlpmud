#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=20;
     spell_level=8;
     casting_time=1;
     duration=0;
     spell_cost=57; /* per critter */
     id_name="fog";
     spell_name="Death Fog";
     spell_desc="This spell creates a cloud of corrosive fog to disolve " +
      "the flesh of your foes. It will deliver 9-135 points of damage.\n\n" +
       "Cost: 171 spell points + 57 for every target over 3\n" +
      "Type: conjuration\n" +
       "Format: cast fog (<target>)\n";
     properties=({ "living_target", "attack_spell", "area_effect" });
     spell_type="conjuration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You take out a small vial of vitriol and blow across " +
  "the open top. The air tingles against your skin, developing an acrid " +
  "flavor.\n"));
  ssay(me, NAME + " takes out a small vial, opens it, and blows across the " +
   "top. The air tingles against your skin, developing an acrid flavor.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  object *ob;
  int i, exp;
  if(targ[0]!=me && !present(targ[0], environment(me))) {
    write("That person is no longer here.\n");
    ssay(0, "The sulfurous smell fades.\n");
    return 1;
  }
  if(targ[0]==me) {
    write(format("You cry out in pain and cancel the effects of the spell " +
     "as your skin starts shriek.\n"));
    ssay(me, NAME + " cries out in pain as a cloud of vapor begins to form " +
     "around him.\n");
    return 1;
  }
  if(!me->valid_attack(targ[0])) {
    ssay(0, "The sulfurous smell fades.\n");
    return 1;
  }
  ssay(0, "A dense fog forms, wilting everything in its path.\n");
  for(i=0; i < sizeof(targ); i++) {
    if(targ[i] && targ[i]!=me && ((object)targ[i]->query_attack()==me ||
     !targ[i]->is_player()) && !targ[i]->id("guild_pet")) {
      tell_object(targ[i], format("Your eyes, skin and lungs protest " +
       "against the acrid vapors. You are burned!\n"));
      ssay(targ[i], targ[i]->query_name() + " gasps and screams as the " +
       "acrid vapors eat at " + targ[i]->query_possessive() + " flesh.\n");
      if(!targ[i]->query_attack())
        targ[i]->attacked_by(me);
      exp=(int)targ[i]->hit_player((random(15) + 1) * 9);
      me->add_exp(exp);
    }
    else  if(targ[i]!=me) {
      tell_object(targ[i], format("You dive out of the way of the " +
       "insidious fog.\n"));
      ssay(targ[i], targ[i]->query_name() + " dives out of the way of the " +
       "insidious fog.\n");
    }
  }
  return 1;
}
