#include "/players/fred/closed/bloodfist/defs.h"
#include "/players/fred/closed/bloodfist/obj/valid_attack.h"

status main(string str, object PO, object User)
{
  int dmg, cost, activity;
  string st, nst, xt;
  object nmy, wep;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(2)) return 0;
  if(!str && User->query_attack())
    nmy = (object)User->query_attack();
  else if(str)
    nmy = valid_attack(str, User);

  if(!nmy)
    return (notify_fail("What do you want to attack?\n"), 0);

  if(!present(nmy, environment(this_player())))
  {
    TOU "You don't see "+nmy->short()+" here.\n");
    return 1;
  }

  if(nmy->query_hp() > (50 + (MIT / 10))
    || (nmy->query_hp() > ((int)nmy->query_mhp() / 10)))
  {
    TOU nmy->short()+" is too powerful to finish off.\n");
    return 1;
  }

  activity = (int)PO->activity_bonus();
  cost = 27 - ((WIS / 20) + (FAI / 50));
  dmg = (int)nmy->query_hp();
  dmg = (int)PO->stance_bonus(dmg);
  PO->add_activity(1);

  if(User->query_sp() < cost)
  {
    TOU "You are too weak to do this now.\n");
    return 1;
  }

  if(!(wep = (object)User->query_weapon()))
  {
    TOU "You pound "+nmy->query_name()+" with your fists!\n");
    TRU Name+" pounds "+nmy->query_name()+" with "+User->POS+" fists!\n",
      ({ User }));
    TRU nmy->query_name()+" dies from the blow.\n");
  }
  else {
    st = (string)wep->short();
    if(User->query_level() >= 40){
      if(sscanf(st, "%s  <%s", nst, xt)){}
    }
    else if(sscanf(st, "%s (%s", nst, xt)){}
    else
      nst = st;

    TOU "You devastate "+nmy->query_name()+" with your "+nst+NORM+"!\n");
    TRU Name+" devastates "+nmy->query_name()+" with "+User->POS+" "+
      nst+NORM+"!\n", ({ User }));
    TRU nmy->query_name()+" dies from the blow.\n");
  }
  nmy->heal_self(-dmg);
  nmy->hit_player((dmg+100), "other|zeus"); /* can't be blocked */
  User->add_sp(-cost);
  return 1;
}

