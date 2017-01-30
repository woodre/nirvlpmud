#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=60;
     spell_level=3;
     casting_time=1;
     duration=20;
     spell_cost=30;
     id_name="invisibility";
     spell_name="Invisibility";
     spell_desc="With this spell you become transparent to all but the " +
      "mightiest users of magic (i.e. wizards). Players will still know " +
      "your identity if you perform an action in a room however.\n\n" +
      "Cost: 30 spell points\n" + 
     "Type: alteration\n" +
      "Format: cast invisibility\n";
     properties=({ "no_attack", "no_target", "self_target", "living_target" });
     spell_type="alteration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You pass your hand over a small glass rod and incant " +
   "invisibility.\n"));
  ssay(me, NAME + " passes " + HIS + " hand over a small glass rod and " +
   "says something.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  write("You fade into transparency.\n");
  ssay(me, NAME + " fades from view.\n");
  me->set_invisibility(19, duration);
  return 1;
}

string casting_message(object targ, object caster, int round) {
}
