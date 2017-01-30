#include "/players/fred/closed/bloodfist/defs.h"
#include "/players/fred/closed/bloodfist/obj/valid_attack.h"

status main(string str, object PO, object User)
{
  int dmg, cost, activity;
  string srt, ns, js;
  object nmy, wep;
  if(User->query_ghost()) return 0;
  if(!PO->level_check(2)) return 0;
  if(!str && User->query_attack())
    nmy = (object)User->query_attack();
  else if(str)
    nmy = valid_attack(str, User);

  if(!nmy)
    return (notify_fail("What do you want to attack?\n"), 0);

  if(User->query_spell_dam())
  {
    TOU "You are already using bash.\n");
    return 1;
  }
    
  if(!nmy)
  {
    TOU"Who do you want to attack?\n");
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
    TOU "You crush "+nmy->query_name()+" with your fists!\n");
    TRU Name+" crushes "+nmy->query_name()+" with "+User->POS+" fists!\n",
      ({ User }));
  }
  else {
    srt = (string)wep->short();
    if(User->query_level() >= 40){
      if(sscanf(srt, "%s  <%s", ns, js)){}
    }
    else if(sscanf(srt, "%s (%s", ns, js)){}
    else
      ns = srt;
    ns += NORM;
    TOU "You crush "+nmy->query_name()+" with your "+ns+"!\n");
    TRU Name+" crushes "+nmy->query_name()+" with "+User->POS+" "+
      ns+"!\n", ({ User }));
  }
  User->spell_object(nmy,"",dmg,cost,"","","");
  if((object)nmy->query_attack() != User)
  {
    TOU nmy->query_name()+" turns "+nmy->POS+" attention towards you!\n");
    TRU nmy->query_name()+" turns "+nmy->POS+" attention towards "+Name+"!\n",
      ({ User }));
    nmy->attack_object(User);
  }

  return 1;
}

