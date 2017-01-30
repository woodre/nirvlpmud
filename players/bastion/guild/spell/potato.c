#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=40;
     spell_level=6;
     casting_time=1;
     duration=0;
     spell_cost=48;
     id_name="potato";
     spell_name="Flying Potato of Doom";
     spell_desc="Created by a rather whimsical (albeit deadly) wizard, " +
      "this spell conjures an enormous tuber over the head of an " +
      "opponent. It then crushes him, doing 8-96 points of damage. Your " +
      "enemies are not liable to laugh long.\n\n" +
      "Cost: 48 spell points\n" +
      "Type: conjuration\n" +
      "Format: cast potato (<target>)\n";
     properties=({ "living_target", "attack_spell" });
     spell_type="conjuration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You do a little dance waving a knife whose cutting " +
   "edges surround a hole in the center of the blade.\n"));
  ssay(me, NAME + " does a little dance waving a knife whose cutting " +
   "edges surround a hole in the center of the blade.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  int exp;
  if(targ[0]!=me && (!targ[0] || !present(targ[0], environment(me)))) {
    write("That person is no longer here.\n");
    return 1;
  }
  if(targ[0]==me) {
    write("You barely avoid being mashed by your own potato.\n");
    ssay(me, NAME + " narrowly avoids being mashed by an enormous potato " +
     "which materializes over " + HIS + " head.\n");
    return 1;
  }
  if(!me->valid_attack(targ[0])) {
    ssay(me, NAME + " stops dancing and looks frustrated.\n");
    return 1;
  }
  ssay(targ[0], "An enormous potato materializes over " + WHO + "'s head " +
   "and proceeds to mash him.\n");
  tell_object(targ[0], format("You are mashed under the weight of an " +
   "enormous potato!\n"));
  if(!targ[0]->query_attack())
    targ[0]->attacked_by(me);
  exp=(int)targ[0]->hit_player((random(12) + 1) * 8);
  me->add_exp(exp);
  return 1;
}
