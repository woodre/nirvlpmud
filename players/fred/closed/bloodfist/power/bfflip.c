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

    TOU format("You flip "+nst+" around in your hand to get a better grip.\n",80));
    TRU format(User->query_name()+" flips "+nst+" around in "+User->query_possessive()+" "+
        "hand to get a better grip.\n",80), ({ User }));
  }
  else
    return (notify_fail("What weapon do you want to flip around?\n"), 0);
  return 1;
}
