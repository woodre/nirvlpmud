#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object it, *all, wep;
  object *inv;
  int x, y;
  string st,nst,nsw,xt;
  int val;
  if(User->query_ghost()) return 0;
  if(!(wep = (object)User->query_weapon()))
  {
    TOU "You do not have a weapon wielded to swap.\n");
    return 1;
  }
  if(wep->queryKept())
  {
    TOU "You are not allowed to swap a weapon that is kept...\n");
    return 1;
  }
  if(!str) /* swap with first weapon */
  {
    all = all_inventory(PO);
    if(sizeof(all) > 0)
      it = all[0];
    else
    {
      TOU "You do not have a weapon sheathed to swap with.\n");
      return 1;
    }
  }
  else {
    it = present(str, PO);
    if(!it)
    {
      if(str == "1") val = 0;
      else if(str == "2") val = 1;
      else if(str == "3") val = 2;
      else if(str == "4") val = 3;
      else if(str == "5") val = 4;
      else if(str == "6") val = 5;

      all = all_inventory(PO);
      if(sizeof(all) > 0)
        it = all[0];
      else
      {
        TOU "You do not have a weapon sheathed to swap with.\n");
        return 1;
      }
    }
    if(!it)
    {
      TOU "What weapon do you want to swap with?\n");
      return 1;
    }
  }
  val = (int)it->query_weight() - (int)wep->query_weight();
  if(val > 0 && !User->add_weight(val))
  {
    TOU "You are too burdened to swap with that weapon.\n");
    return 1;
  }

  st = (string)wep->short();
  if(User->query_level() >= 40){
    if(sscanf(st, "%s  <%s", nst, xt)){}
    else nst = st;
  }
  else if(sscanf(st, "%s (%s", nst, xt)){}
  else
    nst = st;

  st = (string)it->short();
  if(User->query_level() >= 40){
    if(sscanf(st, "%s  <%s", nsw, xt)){}
    else nst = st;
  }
  else if(sscanf(st, "%s (%s", nsw, xt)){}
  else
    nsw = st;

  TOU "You sheath "+nst+" and unsheath "+nsw+".\n");
  TRU User->query_name()+" sheathes "+nst+" and unsheathes "+
    nsw+".\n", ({ User }));

  move_object(it, User);
  /* User->stop_wielding(): */
  wep->stopwield();
  move_object(wep, PO);
  if(it->two_handed())
  {
    inv = all_inventory(User);
    y = sizeof(inv);
    for(x=0; x < y; x++)
    {
      if((string)inv[x]->query_type() == "shield" && inv[x]->query_worn()) 
      {
        TOU "You need both hands free to use this weapon.\n");
        return 1;
      }
    }
  }
        
  call_other(User, "wield", it, 1, it->query_params());
  it->swapped();
  it->set_wielded(1);
  it->set_wielded_by(User);
  User->recalc_carry();
  return 1;
}
