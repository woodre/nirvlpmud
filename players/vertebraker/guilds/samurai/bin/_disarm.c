#include "../def.h"

cmd_disarm(str)
{
  object atk;
  object wep;
  
  if(TP->query_ghost()) return 0;
  if(TP->query_guild_rank() < 7)
  {
    write("You must master your current skills first.\n");
    return 1;
  }
  if(!str)
    atk = TP->query_attack();
  else
    atk = present(str, ENV(TP));
    
  if(!atk)
  {
    write("You must select a target or be in combat.\n");
    return 1;
  }
  
  if(!TP->valid_attack(atk)) return 1;
  if(TP->query_sp() < 50)
  {
    write("You need more energy. [50]\n");
    return 1;
  }
  
  if(!(wep=atk->query_weapon()))
  {
    write(atk->query_name()+" isn't wielding a weapon.\n");
    return 1;
  }
  
  if(query_attribute("disarmed", atk)) {
    write(atk->QN+" has already been disarmed!\n");
    return 1;
  }
  TP->add_sp(-50);
  
  write("You "+HIR+"SLAM"+NORM+" the "+wep->query_name()
  +" out of "+atk->QN+"'s hand!\n");
  say(TP->QN+" "+HIR+"SLAMS"+NORM+" the "+wep->QN
  +" out of "+atk->QN+"'s hand!\n");
  
   atk->stop_wielding();
   wep->set_wielded(0);
   wep->set_wielded_by(0);
   if(wep->query_guild_bonus()) wep->remove_guild_bonus();
   if(!atk->is_player()) { call_out("rewield", TP->query_guild_rank() * 4, ({ atk, wep }));
      add_attribute("disarmed", atk); }
   return 1;
}

rewield(m)
{
  object wep, atk;
  atk = m[0];
  wep = m[1];
  if(atk && wep && present(wep,atk))
  command("wield "+wep->QN, atk);
}
