#include "../defs.h"

status main(string str, object PO, object User)
{
  object ob;
  int bonus;
	
  if(GHOST) return 0;
  if(PO->query_creation() < 2) return 0;
	
  if(PO->query_mp() < 5)
  {
    TOU "You do not have enough "+BOLD+"Dark Matter"+NORM+" for that.\n");
    return 1;
  }

  ob = clone_object("/players/fred/closed/venom2/OBJ/alarm.c");
  ob->set_owner(User->QRN);
  move_object(ob, ENV(User));
  PO->add_mp(-5);
  
  TOU "You place your palm on the ground...\n"+
      "A "+HIW+"Dark Matter Sliver"+NORM+" breaks away and implants itself in the ground.\n");
  TRU User->QN+" places "+User->POS+" palm on the ground...\n"+
      "A "+HIW+"Dark Matter Sliver"+NORM+" breaks away and implants itself in the ground.\n", ({ User }));
  return 1;
}

