#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=70;
     spell_level=2;
     casting_time=1;
     duration=120;
     spell_cost=40;
     id_name="energyblade";
     spell_name="Energy Blade";
     spell_desc="You may create a shimmering blade with which to smite your " +
      "foes. It will last only for the duration of the spell, however, " +
      "which increases with your level.\n\n" +
      "Cost: 40 spell points\n" +
      "Type: conjuration\n" +
      "Format: cast energyblade (<target>)\n";
     properties=({ "self_target", "no_attack", "living_target" });
     spell_type="conjuration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You wave your arms through the air, static teasing the " +
   "hair on your arms.\n"));
  ssay(me, NAME + " waves " + HIS + " arms, the air crackling with static " +
    "around " + HIM + ".\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  object blade;
  if(targ[0]!=me && !present(targ[0], environment(me))) {
    write("That person is not here.\n");
    ssay(me, NAME + " stops waving and frowns.\n");
    return 1;
  }
  blade=clone_object("players/bastion/guild/obj/blade_spell");
  tell_object(targ[0], "A shimmering brand of energy forms in your hands.\n");
  ssay(targ[0], "A shimmering brand of energy forms in " + WHO + "'s hands.\n");
  move_object(blade, targ[0]);
  blade->self_destruct((me->query_level() + me->query_extra_level()) *
   duration);
  return 1;
}

string casting_message(object targ, object caster, int round) {
}
