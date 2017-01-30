#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=40;
     spell_level=5;
     casting_time=1;
     duration=100;
     spell_cost=60;
     id_name="haste";
     spell_name="Haste";
     spell_desc="This spell causes the personal time of the affected " +
      "creature to speed up. All actions related to the creature's heart " +
      "beat will be performed twice as quickly (e.g. fighting, aging). " +
      "Only one haste spell may operate at a time, however.\n\n" +
      "Cost: 60 spell points\n" +
      "Type: alteration\n" +
      "Format: cast haste (<target>)\n";
     properties=({ "living_target", "self_target" });
     spell_type="alteration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You take out a vial of mercury and pass your hand over " +
   "the top.\n"));
  ssay(me, NAME + " takes out a vial of silvery liquid and passes " + HIS +
   " hand over the top.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  object spell;
  string name;
  if(!targ[0] || !present(targ[0], environment(me))) {
    write("That person is not longer here.\n");
    ssay(me, NAME + " sighs and puts the vial away.\n");
    return 1;
  }
  if(targ[0]==me) {
    write(format("The contents of vial glow and the air about you shimmers. " +
     "Everything seems to move much slower.\n"));
    ssay(me, "The contents of the vial in " + NAME + "'s hands glow and the " +
     "air about " + HIM + " shimmers. " + HE + " seems to be moving rapidly" +
     ".\n");
  }
  else {
    name=(string)targ[0]->query_pronoun();
    ssay(targ[0], "The contents of the vial glow and the air about " + WHO +
      " shimmers. " + capitalize(name) + " seems to be " +
     "moving rapidly.\n");
    tell_object(targ[0],format("The contents of the vial in " + NAME + "'s " +
     "hands glow and the air about you shimmers. Everything seems to move " +
     "more slowly.\n"));
  }
  if(present("haste", targ[0]))
    destruct(present("haste", targ[0]));
  spell=clone_object("players/bastion/guild/obj/haste_spell");
  move_object(spell, targ[0]);
  spell->self_destruct(duration);
  return 1;
}

string casting_message(object *targ, object caster, int round) {
}
