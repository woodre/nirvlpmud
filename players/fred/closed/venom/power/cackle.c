#include "../defs.h"

status main(string str, object PO, object User)
{
  if(GHOST) return 0;
  if(PO->query_venomed())
  {
    TOU "You give out a mad cackle, your long pointed tongue lashing about!\n");
    TRU User->QN+ "'s tongue lashes about as "+User->PRO+" cackles maniacally!\n", ({ User }));
    return 1; 
  }
  TOU "You cackle gleefully.\n");
  TRU User->QN+" throws "+User->POS+" head back and cackles with glee!\n", ({ User }));
  return 1;
}
