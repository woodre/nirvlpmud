#include "/players/fred/closed/bloodfist/defs.h"

mixed main(string str, object PO, object User)
{
  object it, *all;
  string st, nst, xt;
  int val, a;
  if(User->query_ghost()) return 0;
  if(!str)
    return (notify_fail("What do you want to unsheath?\n"), 0);
  if(str == "all")
  {
    all = all_inventory(PO);
    val = sizeof(all);
    if(!val)
      return (notify_fail("What do you want to unsheath?\n"),0);
    TOU "You unsheath all your weapons...\n\n");
    for(a = 0; a < val; a++)
    {
      if(User->add_weight(all[a]->query_weight()))
      {
        st = (string)all[a]->short();
        if(User->query_level() >= 40){
          if(sscanf(st, "%s  <%s", nst, xt)){}
        }
        else if(sscanf(st, "%s (%s", nst, xt)){}
        else
          nst = st;
        TOU "You unsheath "+nst+".\n");
        move_object(all[a], User);
        PO->rm_sheathed();
      }
      else
        return (notify_fail("You are too burdened to unsheath anymore.\n"),0);
    }
    return 1;
  }
  it = present(str, PO);
  if(!it)
  {
    if(str == "1") val = 0;
    else if(str == "2") val = 1;
    else if(str == "3") val = 2;
    else if(str == "4") val = 3;
    else if(str == "5") val = 4;
    else if(str == "6") val = 5;
    else 
      return (notify_fail("What do you want to unsheath?\n"), 0);

    all = all_inventory(PO);
    if(sizeof(all) > (val))
      it = all[val];
    else
      return (notify_fail("That weapon is not sheathed.\n"), 0);
  }
  if(PO->query_sheathed() == 0)
    return (notify_fail("You do not have any weapons sheathed.\n"),0);
  if(!User->add_weight(it->query_weight()))
    return (notify_fail("You are too burdened to unsheath that weapon.\n"),0);

  st = (string)it->short();
  if(User->query_level() >= 40){
    if(sscanf(st, "%s  <%s", nst, xt)){}
  }
  else if(sscanf(st, "%s (%s", nst, xt)){}
  else
    nst = st;

  TOU "You unsheath "+nst+".\n");
  TRU User->query_name()+" unsheathes "+nst+".\n", ({ User }));

  PO->rm_sheathed(); /* this just decrements the count */
  move_object(it, User);

  return it;
}

