#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object wep;
  string st, nst, xt, condition;
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

    switch(wep->query_wear()) {
      case 0..39:      condition = "is unblemished and in perfect condition"; break;
      case 40..99:     condition = "has slight scratches along it"; break;
      case 100..199:   condition = "is pitted and nicked in places"; break;
      case 200..399:   condition = "has large nicks and scratches all over it"; break;
      case 400..10000: condition = "has many deep gashes and gouges along it"; break;
      default:         condition = "is in otherwise unremarkable condition"; break;
    }  
      
    TOU format("You hold "+nst+" outstretched in front of your face, "+
        "and carefully look down its length for any imperfections.\n",80));
    TOU format("It "+condition+".\n",70));        
    TRU format(User->query_name()+" holds "+nst+" outstretched in front of "+
        User->query_possessive()+" face, "+
        "and carefully looks down its length for any imperfections.\n",80), ({ User }));
  }
  else
    return (notify_fail("What weapon do you want to eye for imperfections?\n"), 0);
  return 1;
}
