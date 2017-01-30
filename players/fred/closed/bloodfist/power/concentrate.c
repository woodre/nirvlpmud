#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cost;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(5)) return 0;

  cost = (AGL + VIG + ACC + MIT + FAI) / 10;

  if((string)environment(User)->realm() == "NM")
  {
    TOU"Your energy is being drained here.\n");
    return 1;
  }

  if(User->query_sp() < cost)
  {
    TOU "You are too weak to do this now.\n");
    return 1;
  }

  if(PO->query_concentrate()) 
    return (notify_fail("Concentrate is already active.\n"),0);    
  
  if(PO->query_dur() >= PO->query_max_dur())
    return (notify_fail("You can not handle another duration ability.\n"),0);

  TOU "You begin to concentrate on the art of combat.\n"+
    "You feel your abilities have become heightened!\n");

  TRU Name+" begins to concentrate.\n",  ({ User }));

  User->add_sp(-cost);
  PO->concentrate_ss(1); /* start concentration */
  PO->add_dur();
  return 1;
}

