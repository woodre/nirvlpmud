#include "/players/fred/closed/bloodfist/defs.h"
#include "/players/fred/closed/bloodfist/obj/valid_attack.h"
int *rmsgs;

vmsg1(int dmg, object nmy, int y, int z, object User, object PO, int cnt)
{
  int x;
  object wep;
  string msg1;
  for(x = 0; x < cnt; x++)
  {
    if(wep = (object)User->query_weapon())
    {
      string *tp, tp2;
      /*
      if(z)
        tp = (string)first_inventory(User)->query_message_hit(rmsgs[x]);
      else
      */
if (x < sizeof(rmsgs))
        tp = (string)wep->query_message_hit(rmsgs[x]);
else
  tp = (string)wep->query_message_hit(rmsgs[(sizeof(rmsgs)-1)]);
      tp2 = "You ";
      tp2 += tp[1]+" ";
      tp2 += nmy->query_name();
      tp2 += tp[0]+".\n";
      if(!x)
        msg1 = tp2;
      else
        msg1 += tp2;
    }
    else
    {
      switch(y)
      {
        case 0:
          if(!x)
            msg1 = "You strike "+nmy->query_name()+" with your fists!\n";
          else
            msg1 += "You strike "+nmy->query_name()+" with your fists!\n";
          break;
        case 1:
          if(!x)
            msg1 = "Your movements blur as you attack "+nmy->query_name()+
            "!\n";
          else
            msg1 += "Your movements blur as you attack "+nmy->query_name()+
            "!\n";
          break;
        case 2:
          if(!x)
            msg1 = "You attack "+nmy->query_name()+
            " with lightning speed!\n";
          else
            msg1 += "You attack "+nmy->query_name()+
            " with lightning speed!\n";
          break;
        case 3:
          if(!x)
            msg1 = "You strike quickly with your fists!\n";
          else
            msg1 += "You strike quickly with your fists!\n";
          break;
      }
    }
  }
  return msg1;
}

vmsg2(int dmg, object nmy, int y, int z, object User, object PO, int cnt)
{
  string nmn, nm, msg2;
  object wep;
  int x;
  nmn = (string)nmy->query_name();
  nm = capitalize((string)User->query_name());
  for(x = 0; x < cnt; x++)
  {
    if(wep = (object)User->query_weapon())
    {
      string *tp, tp2;
      /*
      if(z)
        tp = (string)first_inventory(User)->query_message_hit(rmsgs[x]);
      else
      */
      if(x < sizeof(rmsgs))
        tp = (string)wep->query_message_hit(rmsgs[x]);
      else
        tp = (string)wep->query_message_hit(rmsgs[(sizeof(rmsgs)-1)]);  
      tp2 = User->query_name()+" ";
      tp2 += tp[1]+" ";
      tp2 += nmy->query_name();
      tp2 += tp[0]+".\n";
      if(!x)
        msg2 = tp2;
      else
        msg2 += tp2;
    }
    else
    {
      switch(y)
      {
        case 0:
          if(!x)
            msg2 = nm+" strikes "+nmn+" with "+User->POS+" fists!\n";
          else
            msg2 += nm+" strikes "+nmn+" with "+User->POS+" fists!\n";
          break;
        case 1:
          if(!x)
            msg2 = nm+"'s movements blur as "+User->PRO+" attacks "+nmn+"!\n";
          else
            msg2 += nm+"'s movements blur as "+User->PRO+" attacks "+nmn+"!\n";
          break;
        case 2:
          if(!x)
            msg2 = nm+" attacks "+nmn+" with lightning speed!\n";
          else
            msg2 += nm+" attacks "+nmn+" with lightning speed!\n";
          break;
        case 3:
          if(!x)
            msg2 = nm+" strikes quickly with "+User->POS+" fists!\n";
          else
            msg2 += nm+" strikes quickly with "+User->POS+" fists!\n";
          break;
      }
    }
  }
  return msg2;
}

status main(string str, object PO, object User)
{
  int dmg, cost, x, activity, cnt, rmsg;
  string st, nst, xt;
  object nmy;
  if(!str && User->query_attack())
    nmy = (object)User->query_attack();
  else if(str)
    nmy = valid_attack(str, User);

  if(!nmy)
    return (notify_fail("What do you want to attack?\n"), 0);

  x = random(4);
  if(User->query_spell_dam())
    return (notify_fail("You are already using vigor.\n"), 0);
    
  activity = (int)PO->activity_bonus();
  cost = 18 - ((WIS / 60) + (FAI / 60)) + (int)PO->query_glevel();
  dmg = (MIT / 55) + (AGL / 9) + (ACC / 55) + random(22 + (AGL / 10)
    + (ACC / 20)) + GOD + activity;
  if(dmg > 60) dmg = 60;
  dmg = (int)PO->stance_bonus(dmg);
  dmg += (int)PO->endurance_bonus();
  if(dmg < 0)
    dmg = 0;

  if(User->query_sp() < cost)
    return (notify_fail("You are too weak to do this now.\n"), 0);

  PO->add_activity(2);

  cnt = (1 + random(AGL / 40));
  rmsgs =  ({ random(dmg), random(dmg), random(dmg), random(dmg), });

  User->spell_object(nmy,"",dmg,cost,vmsg1(dmg,nmy,x,0,User,PO,cnt),
                   "",vmsg2(dmg,nmy,x,0,User,PO,cnt));
  return 1;
}
