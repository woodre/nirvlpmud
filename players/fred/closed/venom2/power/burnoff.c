#include "../defs.h"

status main(string str, object PO, object User)
{
  object ob;
  int bonus;
	
  if(GHOST) return 0;
  if(PO->query_control() < 3) return 0;
	
  if(PO->query_burnoff())
  {
    TOU "Stopping the burnoff process...\n");
    PO->set_burnoff(0);
    return 1;
  }
  if(User->query_sp() < 15 || PO->query_mp() < 5)
  {
    TOU "Your symbiotic link is too weak for that.\n");
    return 1;
  }
  if(User->query_hp() < 50)
  {
    TOU "Your body is too weak to begin this process.\n");
    return 1;
  }

  PO->set_burnoff(1);
  User->add_spell_point(-15);
  PO->add_mp(-5);
  TOU PO->query_color()+"You concentrate and force "+CAP((string)PO->query_symbiote())+" to burnoff the toxins in your body"+NORM+".\n");
  return 1;
}

