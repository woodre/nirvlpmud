#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=0;
     spell_level=9;
     casting_time=2;
     duration=0;
     spell_cost=106; /* per critter */
     id_name="starburst";
     spell_name="Starburst";
     spell_desc="This spells draws upon the power of the very stars. It " +
      "creates a blinding storm of super-heated matter. Vaporizing anything " +
      "within the area of effect, the spell will cause 25-250 points of " +
      "damage.\n\n" +
       "Cost: 318 spell points + 106 for every target over 3\n" +
       "Type: alteration\n" +
       "Format: cast starburst (<target>)\n";
     properties=({ "living_target", "attack_spell", "area_effect" });
     spell_type="alteration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You trace the outline of the constellations in the air, " +
   "forming glowing sigils.\n"));
  ssay(me, NAME + " traces forms in the air, leaving behind glowing sigils " +
   "of power.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  int i, exp;
  if(targ[0]!=me && !present(targ[0], environment(me))) {
    write("That person is no longer here.\n");
    ssay(0, "The sigils fade.\n");
    return 1;
  }
  if(targ[0]==me) {
    write(format("You burn your eyebrows off, not to mention your " +
     "clothing.\n"));
    ssay(me, "The sigils explode, a brilliant field of light surrounding " +
     NAME + ".\n");
    return 1;
  }
  if(!me->valid_attack(targ[0])) {
    ssay(0, "The sigils fade.\n");
    return 1;
  }
  ssay(0, "The sigils explode filling the room with a searing blaze of " +
   "white light!\n");
  for(i=0; i < sizeof(targ); i++) {
    if(targ[i] && targ[i]!=me && ((object)targ[i]->query_attack()==me ||
     !targ[i]->is_player()) && !targ[i]->id("guild_pet")) {
      tell_object(targ[i], format("You are burned in the blast.\n"));
      ssay(targ[i], targ[i]->query_name() + " is burned in the blast.\n");
      if(!targ[i]->query_attack())
        targ[i]->attacked_by(me);
      exp=(int)targ[i]->hit_player((random(10) + 1) * 25);
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

string casting_message(object *targ, object caster, int round) {
  string *mess;
  mess=({ "The sigils glow brighter and a freezing cold jets through the " +
   "room.\n" });
  return mess[round - 1];
}
