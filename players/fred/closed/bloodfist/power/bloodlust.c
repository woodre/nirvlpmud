#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cost, dur;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(8)) return 0;
  if(!HONOR_DAEMON->honor_check(1200))
  {
    TOU "Your Blood Honor is not high enough.\n");
    return 1;
  }

  cost = 110 - (VIG / 10) - (WIS / 10);
  dur = 20 + (VIG / 8) + (FAI / 14) + (AGL / 20);

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

  if(PO->query_bloodlust()) 
    return (notify_fail("Bloodlust is already active.\n"),0);    
  
  if(PO->query_dur() >= PO->query_max_dur())
    return (notify_fail("You can not handle another duration ability.\n"),0);

  TOU RED+"\n ~-~ -~ /- ~`> - "+NORM+"You beckon with your hands"+RED+
    " --`~/ ~- /.~-`\n/~-` ~ -. ~ "+NORM+
    "The blood crystal glows with red light"+RED+
    "~ - - /~- `~\n /..- "+NORM+
    "The venom of bloodlust now courses through your veins"+
    RED+" ~- ~\n\n"+NORM);  

  TRU Name+" is overcome with bloodlust!\n", ({ User }));

  User->add_sp(-cost);
  PO->bloodlust_timer(dur);
  PO->add_dur();
  return 1;
}

