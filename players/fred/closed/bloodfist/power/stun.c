#include "/players/fred/closed/bloodfist/defs.h"
#include "/players/fred/closed/bloodfist/obj/valid_attack.h"

status main(string str, object PO, object User)
{
  int dmg, cost, activity;
  string st, nst, xt;
  object nmy, wep, nmyo;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(5)) return 0;
  if(!str && User->query_attack())
    nmy = (object)User->query_attack();
  else if(str)
    nmy = valid_attack(str, User);

  if(!nmy)
    return (notify_fail("What do you want to attack?\n"), 0);

  if(User->query_spell_dam())
  {
    TOU "You are too drained to do this again.\n");
    return 1;
  }

  activity = (int)PO->activity_bonus();
  cost = 27 - ((WIS / 20) + (FAI / 50));
  dmg = (FAI / 10) + (MIT / 25) + (ACC / 50) + random(25) + GOD + activity;
  dmg = (int)PO->stance_bonus(dmg);
  PO->add_activity(2);

  if(User->query_sp() < cost)
    return (notify_fail("You are too weak to do this now.\n"), 0);

  if(!(wep = (object)User->query_weapon()))
  {
    TOU "You smash "+nmy->short()+" with your fists!\n");
    TRU Name+" smash "+nmy->short()+" with "+User->POS+" fists!\n",
      ({ User }));
  }
  else {
    st = (string)wep->short();
    if(User->query_level() >= 40){
      if(sscanf(st, "%s  <%s", nst, xt)){}
    }
    else if(sscanf(st, "%s (%s", nst, xt)){}
    else
      nst = st;
    TOU "You stun "+nmy->short()+" with your "+nst+"!\n");
    TRU Name+" stuns "+nmy->short()+" with "+User->POS+" "+
      nst+"!\n", ({ User }));
  }
  User->spell_object(nmy,"",dmg,cost,"","","");
  nmyo = (object)nmy->query_attack();
  if(nmyo && (nmyo != User))
  {
    nmyo->stop_fight();
    nmyo->stop_fight();
    nmyo->stop_hunter();
  }
  nmy->stop_fight();
  nmy->stop_fight();
  nmy->stop_hunter();
  User->stop_fight();
  User->stop_fight();
  User->stop_hunter();

  TRU nmy->short()+" looks dazed.\n");
  return 1;
}

