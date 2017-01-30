#include "/players/fred/closed/bloodfist/defs.h"
#include "/players/fred/closed/bloodfist/obj/valid_attack.h"

status main(string str, object PO, object User)
{
  int dmg, cost, activity;
  string st, nst, xt;
  object nmy, wep;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(3)) return 0;
  if(!str && User->query_attack())
    nmy = (object)User->query_attack();
  else if(str)
    nmy = valid_attack(str, User);

  if(!nmy)
    return 1;

  if(User->query_attack()) 
  {
    TOU "You cannot do this while already in combat.\n");
    return 1;
  }

  if(PO->query_att_time())
  {
    TOU "You cannot use that again.\n");
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
    TOU "You attack "+nmy->query_name()+" with your fists!\n");
    TRU Name+" attacks "+nmy->query_name()+" with "+User->POS+" fists!\n",
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
    nst += NORM;
    TOU "You attack "+nmy->query_name()+" with your "+nst+"!\n");
    TRU Name+" attacks "+nmy->query_name()+" with "+User->POS+" "+nst+"!\n",
      ({ User }));
  }
  User->spell_object(nmy,"",0,0,"","","");
  /*
  User->attack_object(nmy);
  */
  User->add_sp(-cost);
  nmy->hit_player(dmg);
  PO->add_att_time(3);
  return 1;
}

