#include "../defs.h"

status main(string str, object PO, object User)
{
  object target,wound;
  int woot,i;
  string msg,msg2,msg3;
  int damage,spamount;
  string wep,where,how;
	
  if(GHOST) return 0;
  if(PO->query_combat() < 2) return 0;
  if(User->query_spell_dam()) return 1;

  if(PO->query_sdelay())
  {
    TOU "You are already using "+PO->query_sdelay()+".\n");
    return 1;
  }
  if(User->query_sp() < (int)PO->query_combat()+ (((int)PO->query_combat()*4)/2))
  {
    TOU "Your symbiotic link is too weak for that.\n");
    return 1;
  }
  if(!User->query_attack())
  {
    TOU PO->query_color()+"You are not fighting!"+NORM+"\n");
    return 1;
  }
  if(PO->check_attackers())
  {
    TOU PO->query_color()+"You are being attacked and cannot do that!"+NORM+"\n");
    return 1;
  }
	
  damage = random(((int)PO->query_combat() * 5) + ((int)PO->query_combat() * 2));
  spamount = (int)PO->query_combat() + (((int)PO->query_combat()*4)/2);
	
  TOU PO->query_color()+"<"+NORM+HIW+"Darts"+NORM+PO->query_color()+">"+NORM+" You hold up your palm out towards your opponent...\n\n");

  if(damage > 6)
  {
    TOU "     ");
    for(i = 0; i < damage / 6; i++)
    {
      if(!random(2)) 
        TOU "  "+BOLD+"__ "+NORM+"");
      else 
        TOU "  "+BOLD+"-- --- "+NORM+"");
    }
    TOU "\n\n");
  }
  else
  {
    TOU"             "+BOLD+"- ---          --- -    "+NORM+" \n");
  }
  
  TOU "\n\n");
  
  TRU User->QN+" holds "+User->POS+" hand palm outward and fires off "+
      " "+((damage / 5)+1)+" "+HIW+"Dark Matter"+NORM+" Darts into "+ATN+".\n", ({ USER }));

  PO->add_mp(-1);
  target = (object)User->query_attack();
  msg   = "";
  msg2 = "";
  msg3 = "";
  User->spell_object(target, PO->query_color()+"Darts"+NORM, damage, spamount,
	msg, msg2, msg3);
  if(random(100) < 20 && !present("wounded_object_venom", target) &&
     PO->query_combat() > 5)
  {
    wound = clone_object("/players/fred/closed/venom2/OBJ/wound.c");
    wound->set_how_many(random(3) + 1);
    move_object(wound, target);
  }
  return 1;
}
