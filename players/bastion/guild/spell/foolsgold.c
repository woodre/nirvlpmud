#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=70;
     spell_level=2;
     casting_time=1;
     duration=0;
     spell_cost=30;
     id_name="foolsgold";
     spell_name="Foolsgold";
     spell_desc="This spell allows you to create an item which looks like " +
      "money. You may set the apparent value of the item to anthing you " +
      "wish.\n\n" +
      "Cost: 30 spell points\n" +
      "Type: conjuration\n" +
      "Format: cast foolsgold <amount>\n";
     properties=({ "non_parsed" });
     spell_type="conjuration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You take out a coin, toss it in the air and concentrate.\n"));
  ssay(me, NAME + " takes out a coin, tosses it in the air and grins.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  int temp;
  object money;
  if(!arg1 || sscanf(arg1, "%d", temp)!=1) {
    write(format("Perhaps you should have concentrated on an amount.\n"));
    ssay(0, "The coin thuds to the ground.\n");
    return 1;
  }
  money=clone_object("obj/treasure");
  money->set_id("money");
  money->set_alias("coins");
  money->set_short(temp + " gold coins");
  write("Coins shower out of the air and into your pockets.\n");
  ssay(me, "Coins shower out of the air and into " + NAME + "'s pockets.\n");
  move_object(money, me);
  return 1;
}

string casting_message(object *targ, object caster, int round) {
}
