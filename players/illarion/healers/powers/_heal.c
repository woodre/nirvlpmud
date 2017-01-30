#include "../def.h"
inherit POWERBASE;

void reset() {
  spell_name = "heal";
  difficulty = 20;
  difficulty_type = "level";
  difficulty_multiplier = 2;
  fail_message = "Your heal spell failed!\n";
  requirements = ([ 
    "living_target" : ({ "0", "You may only heal living things.\n" }),
    "not_self" : ({ "0", "You may only cast fortify upon other Healers.\n" }),
    "level" : ({ 5, "You must be at least level 5 to cast this spell.\n" }),
    "heal_self_sp_check": ({ 0, "That would be pointless.\n" }),
    "sp_amount_check": ({ 0, "You are low on energy.\n" })
  ]);
  /* Heal cost is assessed manually due to various complexities */
  costs = ([  ]);
}

status main(string str, object target, object usr, object gob)
{
  string heal_type;
  string tmp;
  int heal_amount, max_heal_amount;
  int hp_healed, sp_healed;
  int cost;
  status heal_ok;

  heal_type = query_verb();
  
  if(sscanf(str, "%s %d", tmp, heal_amount)!=2)
    heal_amount=(int)gob->query_default_heal_amount();
  if(heal_amount > (max_heal_amount = (int)gob->query_max_heal_amount()))
    heal_amount = max_heal_amount;
    
  hp_healed = (int)target->query_mhp() - (int)target->query_hp();
  sp_healed = (int)target->query_msp() - (int)target->query_sp();
  
  if(heal_type=="sp") hp_healed = 0;
  if(heal_type=="hp" || !query_ip_name(target)) sp_healed = 0;
  
  if(hp_healed+sp_healed < 1)
    FAIL(target->query_name()+" is fully healed.\n");
    
  cost = (hp_healed + sp_healed) / 2;
  if(cost < 2) cost = 2;
  
  if(!query_ip_name(target)) {  /* NPCs get healed for the full amount, but provide far less exp */
    hp_healed /= 4;  
    sp_healed = 0;
  }
  
  if(heal_type == "hp" || target == usr)
  {
    if(!target->add_hit_point(heal_amount))
      heal_ok = 1;
  } else if(heal_type == "sp")
  {
    if(!target->add_spell_point(heal_amount))
      heal_ok = 1;
  } else {
    if(!target->heal_self(heal_amount))
      heal_ok = 1;
  }
  
  if(!heal_ok)
  {
    write("You manage to recover some wasted energy.\n");
    usr->add_spell_point(-cost/2);
    return 1;
  }
  
  usr->add_spell_point(-cost);
  gob->add_light_points(hp_healed + sp_healed);
  
  gob->emote(
    "You lay your hands upon #TN# and heal #TO# for "+hp_healed+"/"+sp_healed+" hp/sp.\n",
    "#MN# lays #MP# hands upon you.  You are healed!\n",
    "#MN# lays #MP# hands upon #TN#.\n",
    usr, target);
  
  return 1;
}

heal_self_sp_check(str, usr, gob, target) {
  if(query_verb()=="sp" && gob==usr)
    return 0;
  return 1;
}

sp_amount_check(str, usr, gob, target) {
  string heal_type;
  string tmp;
  int heal_amount, max_heal_amount;
  
  if(sscanf(str, "%s %d", tmp, heal_amount)!=2)
    heal_amount=gob->query_default_heal_amount();
  if(heal_amount > (max_heal_amount = (int)gob->query_max_heal_amount()))
    heal_amount = max_heal_amount;
    
  if(heal_amount > (int)usr->query_sp())
    return 0;
  return 1;
}

