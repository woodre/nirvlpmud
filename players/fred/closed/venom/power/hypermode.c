#include "../defs.h"

status main(string str, object PO, object User) 
{
  int amt;
        
  if(GHOST) return 0;
  if(!PO->query_venomed()) return 0;
  if(User->QEL < 8) return 0;

/***** Sp cost **********/
  if(PO->query_hyperstat() > 5000)
  {
    amt = 50;
  }
  else if(PO->query_hyperstat() > 1000)
  {
    amt = 55;
  }
  else if(PO->query_hyperstat() > 600)
  {
    amt = 60;
  }
  else if(PO->query_hyperstat() > 300)
  {
    amt = 62;
  }
  else if(PO->query_hyperstat() > 100)
  {
    amt = 65;
  }
  else
  {
    amt = 70;
  }
/*************************/

  if(User->query_sp() < amt)
  {
    TOU	"Your symbiotic link is too weak for that.\n");
    return 1;
  }	
		
  TRU User->QN+" begins to work "+User->OBJ+"self into a frenzy!\n");	
  PO->set_hyper_mode(30 + ((int)User->QEL * 3));
  PO->add_hyperstat(1);
  User->add_spell_point(-(amt));
  return 1;
}
