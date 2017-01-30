#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cost, dur;
  if(str != "cry") return 0;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(4)) return 0;

  cost = 40 - (VIG / 10);
  dur = 20 + (VIG / 5) + (FAI / 20);

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
  
  if(PO->query_battle_cry()) 
    return (notify_fail("Battle cry is already active.\n"),0);   

  if(PO->query_dur() >= PO->query_max_dur())
    return (notify_fail("You can not handle another duration ability.\n"),0);

  TOU "You let out a fearsome battle cry and feel invigorated!\n");
  TRU Name+" lets out a fearsome battle cry!\n", ({ User }));

  User->add_sp(-cost);
  PO->battle_cry_timer(dur);
  PO->add_dur();
  return 1;
}
