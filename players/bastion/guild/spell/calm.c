#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=60;
     spell_level=3;
     casting_time=1;
     duration=0;
     spell_cost=50;
     id_name="calm";
     spell_name="Calamad's Compelling Calm";
     spell_desc="This spells causes all creatures in a room to cease any " +
      "aggressive behavior. It will not effect the undead.\n\n" +
      "Cost: 50 spell points\n" +
      "Type: Enchantment\n" +
      "Format: cast calm\n";
     properties=({ "no_target", "area_effect" });
     spell_type="enchantment";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write("You hum a little tune.\n");
  ssay(me, NAME + " hums a little tune.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  object *here;
  int i;
  ssay(me, "Suddenly " + NAME + "'s humming is accompanied by a host of " +
   "disembodied intruments. " + NAME + "'s little ditty is transformed, " +
   "ornamented and imitated in fugue.\n");
  write(format("Suddenly your humming is joined by a host of disembodied " +
   "instruments. You simple tune is transformed, ornamented and imitated in " +
   "fugue.\n"));
  here=all_inventory(environment(me));
  for(i=0; i < sizeof(here); i++) {
    if(!here[i]->id("undead")) {
      here[i]->stop_fight();
      here[i]->stop_fight();
    }
  }
  return 1;
}

string casting_message(object *targ, object caster, int round) {
}
