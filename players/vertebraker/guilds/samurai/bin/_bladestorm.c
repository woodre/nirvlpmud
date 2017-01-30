#include "../def.h"

/* 08/06/07 Earwax: changed sp cost to 240, for time being */

cmd_bladestorm()
{
  object *atk;
  object *inv;
  object gob;
  object a;


  int s;
  object saved;
  gob = previous_object();
  
#ifdef 0
  /* 07/19/07 Earwax */
  write("This spell has been temporarily disabled due to illegality.\n");
  write("Sorry for the inconvenience, I will have it running ASAP.\n");
  write("-Earwax\n");
  return 1;
#endif
  if(TP->query_ghost()) return 0;

  if(TP->query_guild_rank() < 10)
  {
    write("You must master your current skills first.\n");
    return 1;
  }
  if(this_player()->query_sp() < 240)
  {
    write("You need more energy. [240]\n");
    return 1;
  }
   if(!TP->query_weapon()) {
    write("You must be wielding a weapon!\n");
    return 1;
  }
  if(!(a=this_player()->query_attack()))
  {
    write("You're not in combat.\n");
    return 1;
  }
  if(gob->query_beating() || TP->query_spell_dam()) return 1;
  gob->set_beating(1);
  TP->add_sp(-240);
/*
  if((int)TP->query_attrib("dex") < random(36)) {
     write("\tYou swing your "+TP->query_weapon()->query_name()+" and accidentally cut yourself!\n");
    say(TP->QN+" swings "+possessive(TP)+" "+TP->query_weapon()->query_name()+" and accidentally cuts "+objective(TP)+"self!\n");
    TP->hit_player(TP->query_wc(), "other|vertebraker");
    return 1;
   }
*/
  inv = all_inventory(ENV(TP));
  s = sizeof(inv);
  atk = ({ });
  while(s--)
  {
    if(inv[s] && inv[s]->query_attack() == TP)
    {
      atk += ({ inv[s] });
    }
  }
  s = sizeof(atk);
  saved = TP->query_attack();
  while(s --)
  {
    if(!atk[s] || atk[s]->query_ghost()) continue;
    write("\n\tYou lash out at "+atk[s]->QN+"!\n\n");
    {
      int dam;
      string *msg;
      object *weps;
      int    y;    
     if(TP->query_weapon())
      weps = ({ TP->query_weapon() });
      if(TP->query_second_weapon())
        weps += ({ TP->query_second_weapon() });
      
      y = sizeof(weps);
    
      while(y--)
      {
        if(!atk[s] || atk[s]->query_ghost())
          continue;
        dam = weps[y]->hit(atk[s]);
        if(!atk[s] || atk[s]->query_ghost())
          continue;
        dam += random(weps[y]->weapon_class());
        msg = weps[y]->query_message_hit(dam);
        write("You "+msg[1]+" "+atk[s]->QN+msg[0]+".\n");
        say(TP->QN+" "+msg[1]+" "+atk[s]->QN+msg[0]+".\n");
        if(dam > 20)
          dam = 20;
        atk[s]->hit_player(dam, "magical");
      }
    }
  }
  TP->attack_object(saved);
  return 1;
}
  
