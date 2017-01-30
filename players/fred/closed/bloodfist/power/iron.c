#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cost, dur;
  if(str != "skin") return 0;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(7)) return 0;

  cost = 70 - (WIS / 10) - (FAI / 20);
  dur = 30 + (WIS / 20) + (FAI / 8) + (MIT / 20);

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
  
  if(PO->query_iron_skin()) 
    return (notify_fail("Iron skin is already active.\n"),0);    

  if(PO->query_dur() >= PO->query_max_dur())
    return (notify_fail("You can not handle another duration ability.\n"),0);

  TOU "You drive yourself to fight harder, oblivious to pain.\n");
  TRU Name+" drives "+User->OBJ+"self to fight harder.\n", ({ User }));

  User->add_sp(-cost);
  PO->iron_skin_timer(dur);
  PO->add_dur();
  return 1;
}
