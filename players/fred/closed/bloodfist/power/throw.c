/* Valid Command Syntax:
   1. throw                      - throw current wep at current attacker
   2. throw unsheath             - throw 1st sheathed wep at current attacker
   3. throw <wep>                - throw <wep> at current attacker
   4. throw <npc>                - throw current wep at <npc>
   5. throw unsheath <wep>       - throw sheathed <wep> at current attacker
*/
#include "/players/fred/closed/bloodfist/defs.h"
#include "/players/fred/closed/bloodfist/obj/valid_attack.h"

status main(string str, object PO, object User)
{
  int dmg, cost, activity, weight, odds, good, final;
  string one, two, three, st, nst, xt;
  object nmy, wep, shad;

  if(User->query_ghost()) return 0;
  if(!PO->level_check(3)) return 0;

  if(User->query_spell_dam())
    return (notify_fail("You are too drained to do this again.\n"), 0);

  if(!str)                                                       /**1**/
  {
    if((wep = (object)User->query_weapon())
      && (nmy = (object)User->query_attack())){}
  }
  else if(sscanf(str, "%s %s", one, two) == 2)                   /**5**/
  {
    if((wep = present(one, environment(PO))) && wep->weapon_class()
      && (nmy = valid_attack(two, User))){}
    else if(one == "unsheath")
    {
      if((nmy = (object)User->query_attack()))                   /**5**/
        wep = present(two, PO);
        command("unsheath "+two+"", this_player());      
        command("throw weapon", this_player());
        return 1;
    }
  }
  else if(sscanf(str, "%s", one) == 1)
  {
    if(one == "unsheath")                                        /**2**/
    {
      if((nmy = (object)User->query_attack()))
       command("unsheath 1", this_player());
       command("throw weapon", this_player());
       return 1;
    }
    else if((wep = present(one, environment(PO))) && wep->weapon_class()) /**3**/
    {
      if((nmy = (object)User->query_attack())){}
    }
    else if((nmy = valid_attack(one, User)))                     /**4**/
    {
      if((wep = (object)User->query_weapon())){}
    }
  }
  if(!wep)
    return (notify_fail("What weapon do you want to throw?\n"), 0);
  if(!nmy)
    return (notify_fail("What do you want to attack?\n"), 0);
  if(wep->queryKept())
  {
    TOU "You are not allowed to throw a kept weapon...\n");
    return 1;
  }
  if(wep->query_forged() && !wep->query_socketed())
  {
    TOU "You can't throw a forged weapon...\n");
    return 1;
  }

  weight = (int)wep->query_weight();
  activity = (int)PO->activity_bonus();
  cost = 30 + (WIS / 10) + weight;
  dmg = (MIT / 10) + (AGL / 20) + (ACC / 10) + random(FAI/4) + 
    random((int)wep->weapon_class()) + GOD + activity;
  dmg = (int)PO->stance_bonus(dmg);

  if((string)environment(User)->realm() == "NM")
    return (notify_fail("Your energy is being drained here.\n"), 0);

  if(User->query_sp() < cost)
    return (notify_fail("You are too weak to do this now.\n"), 0);

  PO->add_activity(2);

  st = (string)wep->short();
  if(User->query_level() >= 40){
    if(sscanf(st, "%s  <%s", nst, xt)){}
  }
  else if(sscanf(st, "%s (%s", nst, xt)){}
  else
    nst = st;

  TOU "You throw your "+nst+" at "+nmy->query_name()+".\n");
  TRU Name+" throws "+User->POS+" "+nst+" at "+nmy->query_name()+".\n",
    ({ User }));

  odds = (int)PO->query_glevel() + random(MIT / 10) + random(ACC / 10)
    + random(WIS / 25) + random(FAI / 10) - weight;
  good = random((int)nmy->query_level()) + random((int)nmy->query_ac());

  if(!wep->query_bloodfist_wep_shadow()) /* wep must have a shadow */
  {
    shad = clone_object("/players/fred/closed/bloodfist/obj/wep_shadow.c");
    shad -> set_bloodfist_wep_shadow(wep);
  }

  if(odds > good) /* success */
  {
    TOU nmy->query_name()+" is impaled by your "+nst+"!\n");
    TRU nmy->query_name()+" is impaled by the "+nst+"!\n",  ({ User }));
    final = dmg;

  }
  else if(odds > (good / 2)) /* half success */
  {
    TOU nmy->query_name()+" is hit by your "+nst+"!\n");
    TRU nmy->query_name()+" is hit by the "+nst+"!\n",  ({ User }));
    final = (dmg / 2);
  }
  else if(odds > (good / 4))  /* one quarter success */
  {
    TOU nmy->query_name()+" is grazed by your "+nst+"!\n");
    TRU nmy->query_name()+" is grazed by the "+nst+"!\n", ({ User }));
    final = (dmg / 4);
  }
  else {
    TOU "You miss "+nmy->query_name()+
      ", your weapon falling to the ground.\n");
    TRU Name+" misses "+nmy->query_name()+" entirely.\n", ({ User }));
    final = 1;
  }

  wep->set_owner(User->query_real_name());
  wep->set_rd(2 + ((int)wep->weapon_class() / 7)); /* 2 - 5 sec rd delay */
  wep->drop(1);
  move_object(wep, environment(User));
  User->recalc_carry();

  User->spell_object(nmy,"",final,cost,"","",""); /* 0 doesn't count */
  return 1;
}

