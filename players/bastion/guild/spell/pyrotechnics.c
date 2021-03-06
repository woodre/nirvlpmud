#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=80;
     spell_level=2;
     casting_time=1;
     duration=0;
     spell_cost=8; /* per critter */
     id_name="pyrotechnics";
     spell_name="Pyrotechnics";
     spell_desc="This spell creates a shower of multi-hued sparks. Anyone " +
      "affected by the pyrotechnic display takes 5-20 points of damage.\n\n" +
       "Cost: 24 spell points + 8 for every target over 3\n" +
      "Type: conjuration\n" +
       "Format: cast pyrotechnics (<target>)\n";
     properties=({ "living_target", "attack_spell", "area_effect" });
     spell_type="conjuration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You throw your hands out before you, releasing a shower " +
   "of colored sparks.\n"));
  ssay(me, NAME + " throws " + HIS + " hands out before " + HIM + 
   " releasing a shower of colored sparks.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  int i, exp;
  if(targ[0]!=me && !present(targ[0], environment(me))) {
    write("That person is no longer here.\n");
    ssay(0, "The sparks fade and disappear.\n");
    return 1;
  }
  if(targ[0]==me) {
    write(format("You shower yourself in a dazzling display of multi-" +
     "colored sparks. Unfortunately, this really hurts!\n"));
    ssay(me, NAME + " showers " + HIM + "self in a dazzling display of " +
     "multi-colored sparks. " + NAME + " then curses.\n");
    return 1;
  }
  if(!me->valid_attack(targ[0])) {
    ssay(0, "The sparks fade away to nothing.\n");
    return 1;
  }
  for(i=0; i < sizeof(targ); i++) {
    if(targ[i] && targ[i]!=me && ((object)targ[i]->query_attack()==me ||
     !targ[i]->is_player()) && !targ[i]->id("guild_pet")) {
      tell_object(targ[i], format("The sparks explode, burning you.\n"));
      ssay(targ[i], "The sparks explode, burning " + targ[i]->query_name() + 
       ".\n");
      if(!targ[i]->query_attack())
        targ[i]->attacked_by(me);
      exp=(int)targ[i]->hit_player((random(4) + 1) * 5);
      me->add_exp(exp);
    }
    else  if(targ[i]!=me) {
      tell_object(targ[i], format("You dive out of the way as the sparks " +
       "explode.\n"));
      ssay(targ[i], targ[i]->query_name() + " dives out of the way as the " +
       "sparks explode.\n");
    }
  }
  return 1;
}
