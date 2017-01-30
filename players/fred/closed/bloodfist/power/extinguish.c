#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  if(str != "torch") return 0;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(1)) return 0;
  if(!PO->query_torch())
  {
    TOU"You don't have a torch lit to extinguish.\n");
    return 1;
  }
  TOU"You extinguish your torch.\n");
  TRU Name+" extinguishes "+User->POS+" torch.\n", ({ User }));
  PO->toggle_torch();
  return 1;
}
