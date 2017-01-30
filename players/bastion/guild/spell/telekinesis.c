#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=50;
     spell_level=4;
     casting_time=1;
     duration=0;
     spell_cost=30;
     id_name="telekinesis";
     spell_name="Telekinesis";
     spell_desc="This spell allows you to send an object from your " +
      "inventory to another player.\n\n" +
      "Cost: 30 spell points\n" +
      "Type: alteration\n" +
      "Format: cast telekinesis <player> <object>\n";
     properties=({ "two_arguments", "living_target", "distant_target" });
     spell_type="alteration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  if(present(arg2, me)) {
    write("You pass your hand over the " + arg2 + ".\n");
    ssay(me, NAME + " passes " + HIS + " hand over the " + arg2 + ".\n");
  }
  else {
    write(format("You pass your hand over an imaginary " + arg2 + ".\n"));
    ssay(me, NAME + " passes " + HIS + " hand over empty air.\n");
  }
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  object ob;
  int test;
  if(!present(arg2, me)) {
    write("You don't seem to have the " + arg2 + ".\n");
    return 1;
  }
  ob=present(arg2, me);
  test=transfer(ob, targ[0]);
  if(test==0) {
    ssay(0, "The " + arg2 + " floats up and away.\n");
    tell_object(targ[0], "A " + arg2 + " floats into your inventory.\n");
  }
  else if(test==1) {
    write(WHO + " can't carry that much.\n");
    transfer(ob, me);
  }
  else {
    write("You aren't able to give that to " + WHO + ".\n");
    transfer(ob, me);
  }
  return 1;
}

string casting_message(object *targ, object caster, int round) {
}
