#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cost, dur;
  if(str != "aura") return 0;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(6)) return 0;

  cost = 75 - (MIT / 10) - (FAI / 9);
  dur = 12 + (VIG / 12) + (FAI / 14) + (MIT / 20);

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
  
  if(PO->query_pain_aura()) 
    return (notify_fail("Pain aura is already active.\n"),0);    

  if(PO->query_dur() >= PO->query_max_dur())
    return (notify_fail("You can not handle another duration ability.\n"),0);

  TOU "You begin to draw strength from your pain!\n");
  TRU Name+" draws strength from "+User->POS+" pain!\n", ({ User }));

  User->add_sp(-cost);
  PO->pain_aura_timer(dur);
  PO->add_dur();
  return 1;
}

