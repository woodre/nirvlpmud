#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=80;
     spell_level=1;
     casting_time=1;
     duration=0;
     spell_cost=10;
     id_name="werelight";
     spell_name="Werelight";
     spell_desc="This spell creates a magical sphere of luminescence to " +
       "light the darkest of ways. The werelight may be turned on and off " +
       "in order to conserve energy.\n\n"+
       "Cost: 10 spell points\n" +
      "Type: conjuration\n" +
       "Format: cast light (<target>)\n";
     properties=({ "self_target", "living_target", "no_attack" });
     spell_type="conjuration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  if(targ[0]==me)
    write("You cast werelight.\n");
  else
    write("You cast werelight on " + WHO + ".\n");
  ssay(me, NAME + " mumbles something and raises " + HIS + " eyes upward.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
     object ob;
     if(targ[0]!=me && (!targ[0] || !present(targ[0], environment(me)))) {
       write("That person is no longer here.\n");
       return 1;
     }
     ob=clone_object("obj/torch");
     ob->set_name("werelight");
     ob->set_short("A werelight");
     ob->set_long("It is a small, glowing sphere of light.\n");
     ob->set_fuel(2000);
     tell_object(targ[0], "A werelight appears in your hands.\n");
     ssay(targ[0], WHO + " suddenly has a werelight.\n");
     move_object(ob, targ[0]);
     return 1;
}

string casting_message(object targ, object caster, int round) {
}
