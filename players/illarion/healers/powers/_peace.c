#include "../def.h"
inherit POWERBASE;

void reset() {
  spell_name = "peace";
  default_target = "room";
  difficulty = 20;
  difficulty_type = "piety";
  difficulty_multiplier = 1;
  fail_message = "Your peace spell failed!\n";
  requirements = ([ 
    "living_target" : ({ "0", "You may only cast peace upon living things.\n" }),
    "level" : ({ 5, "You must be at least level 5 to call for peace.\n" }),
    "sp" : ({ 35, "You are low on energy.\n" }),
    "exp" : ({  50, "Not enough light.\n" }),
    "coins" : ({ 100, "You are low on coins.\n" }),
    "target_combat_check" : ({ 0, "Your target must be in combat.\n" }),
  ]);
  costs = ([ "sp" : 35, "exp" : 50, "coins" : 100 ]);
}

status main(string str, object target, object usr, object gob)
{
  object attacker;
  if(target) {
    attacker = (object)target->query_attack();
    attacker->stop_fight();
    target->stop_fight();
    attacker->stop_fight();
    target->stop_fight();
    if(target == usr) {
      DAEM->do_emote("You call a stop to your fight with #TN#.\n",
        "#MN calls a stop to #MP# fight with you.\n",
        "#MN calls a stop to #MP# fight with #TN#.\n", usr, attacker);
    } else if(attacker == usr) {
       DAEM->do_emote("You call a stop to your fight with #TN#.\n",
        "#MN calls a stop to #MP# fight with you.\n",
        "#MN calls a stop to #MP# fight with #TN#.\n", usr, target);
    } else {
      write("You call a stop to the fight between "+target->query_name()+" and "+attacker->query_name()+".\n");
      tell_object(target, usr->query_name()+" calls a stop to your fight with "+attacker->query_name()+".\n");
      tell_object(attacker, usr->query_name()+" calls a stop to your fight with "+target->query_name()+".\n");
      tell_room(environment(usr),
        usr->query_name()+" calls a stop to the fight between "+target->query_name()+" and "+attacker->query_name()+".\n",
        ({ usr, attacker, target }));
    }
  } else {
    object *all;
    int s;
    all = all_inventory(environment(usr));
    s = sizeof(all);
    while(s--)
    {
      if(living(all[s])) {
        attacker = (object)all[s]->query_attack();
        if(attacker) {
          attacker->stop_fight(); all[s]->stop_fight();
          attacker->stop_fight(); all[s]->stop_fight();
        }
      }
    }
    DAEM->do_emote("You call a stop to all fighting!\n", 0, "#MN calls PEACE upon all.\n", usr, 0);
  }
  return 1;
}

target_combat_check(str, usr, gob, target) {
  if(target) {
    object attacker;
    attacker = target->query_attack();
    if(!attacker)
      return 0;
  }
  return 1;
}