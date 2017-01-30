#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object wep, shad;
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
   
    if(wep->queryKept())
    {
      TOU "You can not plunge a kept weapon.\n");
      return 1;
    }

    TOU "You raise "+nst+NORM+" into the air, let out a bellowing scream,\n"+
      "and with a violent thrust you plunge "+nst+NORM+" into the ground.\n");
    TRU User->query_name()+" raises "+nst+
      " into the air, lets out a bellowing scream,\n"+
      "and with a violent thrust plunges "+User->POS+" "+nst+
      " into the ground.\n", ({ User }));

    if(!wep->query_bloodfist_wep_shadow())
    {
      shad = clone_object("/players/fred/closed/bloodfist/obj/wep_shadow.c");
      shad->set_bloodfist_wep_shadow(wep);
    }

    wep->set_owner(User->query_real_name());
    wep->set_plunge();
    wep->drop(1);
    move_object(wep, environment(User));
    User->recalc_carry();
  }
  else
    return (notify_fail("What weapon do you want to plunge?\n"), 0);
  return 1;
}
