#include "base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=60;
     spell_level=3;
     casting_time=1;
     duration=0;
     spell_cost=50;
     id_name="identify";
     spell_name="Identify";
     spell_desc="This spell will allow you to learn the vital statistics " +
      "of any creature or object.\n\n" +
      "Cost: 50 spell points\n" +
      "Type: astrology\n" +
      "Format: cast identify <object>\n";
     properties=({ "living_target", "nonliving_target", "no_attack" });
     spell_type="astrology";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You scrutize the " + WHO + " and cast identify.\n"));
  ssay(me, NAME + " scrutinizes the " + WHO + " and mumbles something.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  if(!targ[0]) {
    write("Odd, that is no longer here.\n");
    ssay(me, NAME + " stops muttering and looks surprised.\n");
    return 1;
  }
  write("\n" + targ[0]->short() + "\n");
  write("**************************\n");
  write("Name:\t\t" + targ[0]->query_name() + "\n");
  if(targ[0]->query_info())
    write("Magic info:\t" + targ[0]->query_info() + "\n");
  if(targ[0]->query_level())
    write("Level:\t\t" + targ[0]->query_level() + "\n");
  if(targ[0]->query_hp())
    write("Hit points:\t" + targ[0]->query_hp() + "\n");
  if(targ[0]->query_wc())
    write("Weapon class:\t" + targ[0]->query_wc() + "\n");
  if(targ[0]->query_ac())
    write("Armor class:\t" + targ[0]->query_ac() + "\n");
  if(targ[0]->weapon_class())
    write("Weapon class:\t" + targ[0]->weapon_class() + "\n");
  if(targ[0]->armor_class())
    write("Armor class:\t" + targ[0]->armor_class() + "\n");
  if(targ[0]->query_weight())
    write("Weight:\t\t" + targ[0]->query_weight() + "\n");
  if(targ[0]->query_value())
    write("Value:\t\t" + targ[0]->query_value() + "\n");
  if(targ[0]->query_money())
    write("Money:\t\t" + targ[0]->query_money() + "\n");
  if(living(targ[0]))
    write("Alignment:\t" + targ[0]->query_alignment() + "\n");
  write("->> ");
  return 1;
}

string casting_message(object *targ, object caster, int round) {
}
