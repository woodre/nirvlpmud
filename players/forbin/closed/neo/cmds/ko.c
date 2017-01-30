#include "../defs.h"


status main(string str, object PO, object User)
{
  object target, comp;
  object pob;
  int spamount;
  int cost;
  object uncon_mob;
	
  if(GHOST) return 0;
  if(PO->query_combat() < 4) return 0;

  if(!User->query_attack())
  {
    TOU PO->query_color()+"You can only do this in combat!"+NORM+"\n");
    return 1;
  }

  target = (object)User->query_attack();
  if(!target->query_npc())
  {
    TOU "You cannot do this to players!\n");
    return 1;
  }

  cost = (int)target->query_hp()/3;
  if(cost > User->query_sp())
  {
    TOU "You are too low on energy for an attack of that sort.\n");
    return 1;
  }
  if(target->webbed() || target->confused())
  {
    TOU "Something is keeping you from being able to knock it unconscious.\n");
    return 1;
  }

  if(User->query_attack() && target->query_hp() < 90)
  {
    if(((int)target->query_hp()*10)/((int)target->query_mhp()) < 1)
    {
      target->stop_con_shadow();  /* In case it is webbed */
      uncon_mob = clone_object("/players/fred/closed/venom2/OBJ/uncon_mob.c");
      uncon_mob->store_gender(target->query_gender());
      uncon_mob->store_name(target->query_name());
      uncon_mob->store_level(target->query_level());
      uncon_mob->store_short(target->short());
      uncon_mob->store_spell_dam(target->query_spell_dam());
      uncon_mob->store_spell_chance(target->query_spell_chance());
      uncon_mob->store_heal_rate(target->query_heal_rate());
      uncon_mob->store_heal_intv(target->query_heal_intv());
      uncon_mob->store_mhp(target->query_mhp());
      uncon_mob->store_ac(target->query_ac());
      uncon_mob->store_wc(target->query_wc());
      move_object(uncon_mob, ENV(User));
      target->transfer_all_to(ENV(target));
     
      if(pob = present("party object", User))
        pob->share_exp(target->calculate_worth());
      else
        User->add_exp(target->calculate_worth());

      TOU "You reach out and wrap tentacles around the neck of "+target->QN+"...\n"+
          "Other tentacles lash out and knock them unconscious,\n"+
          "leaving them lying on the ground.\n");
  
      TRU User->QN+" reaches out with tentacles of "+HIW+"Dark Matter"+NORM+"...\n"+
          target->QN+" is strangled to the ground and left lying unconscious.\n", ({ User }));

      User->add_spell_point(-cost);
      target->second_life();
      destruct(target);
      return 1;
    }
    TOU "Your opponent is still too strong.\n");
    return 1;
  }
  TOU "Your opponent is still too strong.\n");
  return 1;
}
