#include "../defs.h"

status main(string str, object PO, object User) 
{
  object target, comp;
  int z;
  int how_many;
  int damage, damage2, amt; 
  string atkmsg, msg, msg2, msg3;
          
  if(GHOST) return 0;
  if(!PO->query_venomed()) return 0;
  if(User->checkNM()) return 0;
  if(User->query_spell_dam()) return 1;
  if(User->QL < 12) return 0;
  if(PO->query_bite_delay())
  {
    TOU "You cannot bite again so soon.\n");
    return 1; 
  }
  if(PO->query_webf_delay()) return 1;
  if(PO->query_hardened()) return 1;

/***** Sp cost **********/
  if(PO->query_bitestat() > 5000)
  {
    amt = 25;
  }
  else if(PO->query_bitestat() > 1000)
  {
    amt = 27;
  }
  else if(PO->query_bitestat() > 600)
  {
    amt = 30;
  }
  else if(PO->query_bitestat() > 300)
  {
    amt = 32;
  }
  else
  {
    amt = 36;
  }
/*************************/

  if(User->query_sp() < amt)
  {
    TOU	"Your symbiotic link is too weak for that.\n");
    return 1;
  }	
  if(User->query_attack())
    target = (object)User->query_attack();
  
  else if(!User->query_attack())
  {
    TOU "You can only do this in combat!\n");
    return 1; 
  }
  if(!present(target, ENV(User)))
  {
    TOU "You don't see them here!\n");
    return 1;
  }
  how_many = random(WIL / 4) + 1;
  damage = 0;

  if(how_many > 4) how_many = 4;

  TRU BOLD+CAP((string)PO->query_symbiote())+NORM+" cackles with glee!\n");

  while(how_many > 0)
  {
    damage += (4 + random(3));
    TOU "<"+HIR+"bite"+NORM+"> A tentacle lashes out from "+BOLD+CAP((string)PO->query_symbiote())+NORM+". Flesh is devoured.\n");
    tell_object(target,
      "<"+HIR+"bite"+NORM+"> A tentacle lashes out at you from "+BOLD+CAP((string)PO->query_symbiote())+NORM+". Flesh is devoured.\n");
    User->add_hit_point(random(2) + 1);
    how_many--;
  }

  if(PO->query_bitestat() > 5000)
  {
    damage += (4 + random(3));
    damage += (4 + random(3));
  }
  else if(PO->query_bitestat() > 600)
  {
    damage += (4 + random(3));
  }

  PO->add_bitestat(1);
  PO->add_mp(-4);
  PO->add_bite_delay(5 + random(3)); 
  msg = "";
  msg2 = "";
  msg3 = "";

  User->spell_object(target, "bite attack", damage, amt, 
	msg, msg2, msg3);
 
  return 1;
}
