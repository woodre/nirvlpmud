#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object it, *its;
  string st, nst, xt;
  int a, sa;
  if(User->query_ghost()) return 0;
  if(!str)
    return (notify_fail("What do you want to sheath?\n"), 0);
  if(str == "all")
  {
    its = all_inventory(User);
    sa = sizeof(its);
    TOU "You sheath all your unwielded weapons...\n\n");
    for(a = 0; a < sa; a++)
    {
      if(its[a]->weapon_class() && !its[a]->query_wielded()
        && (PO->query_sheathed() < PO->query_max_sheathed()))
      {
        st = (string)its[a]->short();
        if(User->query_level() >= 40){
          if(sscanf(st, "%s  <%s", nst, xt)){}
        }
        else if(sscanf(st, "%s (%s", nst, xt)){}
        else
          nst = st;
        TOU "You sheath "+nst+".\n");
        TRU User->query_name()+" sheathes "+nst+".\n", ({ User }));
        PO->add_sheathed();
        move_object(its[a], PO);
      }
      else if(PO->query_sheathed() >= PO->query_max_sheathed())
        return (notify_fail(
          "The burden would be too great to sheath another weapon.\n"),0);
    }
    return 1;
  }
  it = present(str, User);
  if(!it)
    it = present(str, environment(User));
  if(it && !it->weapon_class())
    return (notify_fail("That can not be sheathed.\n"), 0);
  else if(!it)
    return (notify_fail("You do not have that weapon to sheath.\n"), 0);
  if(it->drop())
    return (notify_fail("That can not be sheathed.\n"), 0);
  if(PO->query_sheathed() >= PO->query_max_sheathed())
    return (notify_fail(
      "The burden would be too great to sheath another weapon.\n"),0);

  st = (string)it->short();
  if(User->query_level() >= 40){
    if(sscanf(st, "%s  <%s", nst, xt)){}
  }
  else if(sscanf(st, "%s (%s", nst, xt)){}
  else
    nst = st;

  TOU "You sheath "+nst+".\n");
  TRU User->query_name()+" sheathes "+nst+".\n", ({ User }));

  PO->add_sheathed();
  move_object(it, PO);
  User->add_weight((int)it->query_weight() * -1);
  return 1;
}
