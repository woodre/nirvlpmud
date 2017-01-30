#include "../defs.h"

status main(string str, object PO, object User)
{
  int amt;
	
  if(GHOST) return 0;
  if(PO->query_control() < 6) return 0;

  if(PO->query_regen())
  {
    TOU "You call the "+HIW+"Dark Matter"+NORM+" to stop regenerating your body.\n");
    PO->set_regen(0);
    return 1;
  }
  if(User->query_sp() < 10 || PO->query_mp() < 1)
  {
    TOU "Your symbiotic link is too weak for that.\n");
    return 1;
  }

  TOU PO->query_color()+"-- --"+NORM+" You concentrate and call "+HIW+"Dark Matter"+NORM+" to seal your wounds.\n");
  PO->set_regen(1);
  User->add_spell_point(-10);
  PO->add_mp(-1);
  return 1;
}
