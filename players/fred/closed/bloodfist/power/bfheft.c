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

    TOU format("You heft "+nst+" high above your head, then bring "+
        "it quickly down in a mock deathblow.\n",80));
    TRU format(User->query_name()+" hefts "+nst+" high above "+User->query_possessive()+" "+
        "head, then quickly brings "+
        "it down in a mock deathblow.\n",80), ({ User }));
  }
  else
    return (notify_fail("What weapon do you want to heft above your head?\n"), 0);
  return 1;
}
