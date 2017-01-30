#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object atk;
  if(User->query_ghost()) return 0;
  if((atk = (object)User->query_attack())
    && present(atk, environment(User)))
  {
    TOU "You can't rest while you're fighting.\n");
    return 1;
  }
  if(PO->rest_check())
  {
    TOU "You are already fully rested.\n");
    return 1;
  }
  if(!PO->start_resting(environment(User)))
  {
    TOU "You stop resting.\n");
    PO->stop_resting();
    return 1;
  }
  

  TOU "You begin to rest and recuperate your endurance.\n");
  TRU Name+" begins to rest.\n", ({ User }));

  return 1;
}

