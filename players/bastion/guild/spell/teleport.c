#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=40;
     spell_level=6;
     casting_time=1;
     duration=0;
     spell_cost=80;
     id_name="teleport";
     spell_name="Teleport";
     spell_desc="This spell creates a inter-dimensional rift through which " +
      "the caster may travel. The destination must be the location of " +
      "another player, however.\n\n" +
      "Cost: 80 spell points\n" +
      "Type: alteration\n" +
      "Format: cast teleport <who>\n";
     properties=({ "living_target", "distant_target" });
     spell_type="alteration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You incant teleport and are enveloped in a coruscating " +
   "white light.\n"));
  ssay(me, NAME + " says something and is enveloped in a coruscating " +
   "white light.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  object dest_ob, here;
  if(!targ[0] || (int)targ[0]->query_invis() > 19) {
    write("That person is no longer logged in.\n");
    ssay(me, "The light fades, leaving " + NAME + " looking annoyed.\n");
    return 1;
  }
  here=environment(me);
  dest_ob=environment(targ[0]);
  if(here->realm("NT") || dest_ob->realm("NT") || (me->query_pl_k() &&
    targ[0]->query_pl_k()) || targ[0]->query_level() > 19) {
    write("A folding of space prevents you from transporting.\n");
    ssay(me, "The light fades, leaving " + NAME + " looking annoyed.\n");
    return 1;
  }
  write(format("You feel your every atom pulled apart as you move " +
   "between the dimensions.\n"));
  write("You reappear elsewhere.\n");
  ssay(me, "When the light fades, " + NAME + " is gone.\n");
  tell_room(dest_ob, NAME + " appears in a flash of white light.\n");
  move_object(me, dest_ob);
  return 1;
}

string casting_message(object *targ, object caster, int round) {
}
