#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cost, dur;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(4)) return 0;
  if(!HONOR_DAEMON->honor_check(400))
  {
    TOU "Your Blood Honor is not high enough.\n");
    return 1;
  }

  if(PO->query_bloodboil())
  {
    TOU "You calm your angry blood...\n");
    PO->bloodboil_timer(0);
    PO->durmm();
    return 1;
  }

  cost = 30 - (WIS / 10) - (FAI / 20);
  dur = 20 + (WIS / 20) + (FAI / 8);

  if((string)environment(User)->realm() == "NM")
  {
    TOU"Your energy is being drained here.\n");
    return 1;
  }
 
  if(PO->query_dur() >= PO->query_max_dur())
    return (notify_fail("You can not handle another duration ability.\n"),0);

  if(User->query_sp() < cost)
  {
    TOU "You are too weak to do this now.\n");
    return 1;
  }
  TOU "The blood crystal seems to light a fire inside you...\n\n\n"+
    RED+"Your blood begins to boil...\n"+NORM);
  TRU RED+Name+"'s blood begins to boil.\n"+NORM, ({ User }));

  User->add_sp(-cost);
  PO->bloodboil_timer(dur);
  PO->add_dur();    
  return 1;
}
