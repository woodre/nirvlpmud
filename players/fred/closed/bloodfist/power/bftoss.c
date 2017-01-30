#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object wep, shad;
  string st, nst, xt;
  if(!str)
  {
    TOU "What would you like to toss?\n");
    return 1;
  }
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
      TOU "You can not toss a kept weapon.\n");
      return 1;
    }

    TOU format("You smirk before closing your eyes and slinging "+nst+" high into "+
        "the air above you.  At the last second, you deftly step aside as "+
        "the weapon is embedded into the ground.  "+
        "You smile as you open your eyes to glance at your weapon.\n", 80));
    TRU format(User->query_name()+" smirks before closing "+User->query_possessive()+" "+
        "eyes and slinging "+nst+" into the "+
        "air above "+User->query_objective()+".  At the last second, "+
        User->query_pronoun()+" deftly steps aside as "+
        "the weapon is embedded into the ground.  "+
        User->query_name()+" smiles as "+User->query_pronoun()+" opens "+
        User->query_possessive()+" eyes to glance at "+
        User->query_possessive()+" weapon.",80), ({ User }));

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
    return (notify_fail("What weapon do you want to toss into the air?\n"), 0);
  return 1;
}
