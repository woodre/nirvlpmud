#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  int cost, dur;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(6)) return 0;

  if((PO->query_dur() >= PO->query_max_dur()) && !PO->query_dodge())
    return (notify_fail("You can not handle another duration ability.\n"),0);

  if((int)PO->toggle_dodge() == 1) /* start dodge */
  {
    PO->add_dur();
    TOU "You will now try to dodge attacks.\n");
  }
  else {
    TOU "You will no longer try to dodge attacks.\n");
    PO->durmm();
  }

  return 1;
}
