#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object wep;
  string st, nst, xt;
  if(!str) return 0;
  else if((str == "weapon" || str == "wep")
    && (wep = (object)User->query_weapon()) || (wep = present(str, User)))
  {
    st = (string)wep->short();
    if(User->query_level() >= 40){
      if(sscanf(st, "%s  <%s", nst, xt)){}
      else nst = st;
    }
    else if(sscanf(st, "%s (%s", nst, xt)){}
    else
      nst = st;

    if(!wep->is_weapon())
      return (notify_fail(capitalize(str)+" is not a weapon.\n"), 0);

    TOU format("You sweep "+nst+" through the air in front of you, "+
        "slicing an \"X\" in the emptiness before you.\n",80));
    TRU format(User->query_name()+" sweeps "+nst+" through the air in front of "+
        User->query_objective()+", "+
        "slicing an \"X\" in the emptiness before "
        +User->query_objective()+".\n",80), ({ User }));
  }
  else
    return (notify_fail("What weapon do you want to sweep before you?\n"), 0);
  return 1;
}
