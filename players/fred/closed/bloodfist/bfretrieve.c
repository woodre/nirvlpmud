#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object wep, r, *env;
  int a,c,w,d,e;
  if(User->query_ghost()) return 0;
  if(!str) return 0;
  if(str == "all")
  {
    env = all_inventory(environment(User));
    c = sizeof(env);
    d = 0;
    e = 0;
    for(a = 0; a < c; a++)
    {
      if(env[a]->query_bloodfist_wep_shadow())
      {
        TOU env[a]->short()+" ... ");
        if(env[a]->query_owner() != User->query_real_name())
        {
          e = 1;
          TOU "not yours.\n");
          env[a]->set_rd(1);
        }
        else if(env[a]->query_rd() && (r = (object)User->query_attack())
          && present(r, environment(User)))
        {
          e = 1;
          TOU "not yet.\n");
        }
        else if(env[a]->query_rd())
          env[a]->set_rd(0);
        if(!env[a]->query_rd())
        {
          if(PO->query_a_s()) /* if auto-sheath */
          {
            if(PO->query_sheathed() >= PO->query_max_sheathed())
            {
              TOU "too many sheathed.\n");
              return 1;
            }
            d = 1;
            TOU "okay [sheathed].\n");
            TRU Name+" retrieves and sheathes "+env[a]->short()+".\n",
              ({ User }));
            PO->add_sheathed();
            env[a]->unlock();
            move_object(env[a], PO);
          }
          else {              /* don't auto sheath */
            w = (int)env[a]->query_weight();
            if(!User->add_weight(w))
              TOU "too heavy.\n");
            else {
              d = 1;
              TOU "okay.\n");
              TRU Name+" retrieves "+env[a]->short()+".\n",
                ({ User }));
              env[a]->unlock();
              move_object(env[a], User);
            }
          }
        }
      }
    }
    if(!d && !e)
      TOU "There are no weapons to retrieve here.\n");
    else if(!d && e)
      TOU "You can't retrieve any of these weapons yet.\n");
    return 1;
  }
  if(!(wep = present(str, environment(User))))
    return (notify_fail("What weapon do you want to retrieve?\n"), 0);
  if(!wep->query_bloodfist_wep_shadow())
    return (notify_fail("That weapon cannot be retrieved.\n"), 0);
  if(wep->query_rd() && (r = (object)User->query_attack())
    && present(r, environment(User)))
    return (notify_fail("That weapon cannot be retrieved yet.\n"), 0);

  else if(wep->query_rd())
    wep->set_rd(0);

  if(wep->query_owner() != User->query_real_name())
    return (notify_fail("That weapon is not yours to retrieve.\n"), 0);

  if(PO->query_a_s()) /* if auto sheath */
  {
    if(PO->query_sheathed() >= PO->query_max_sheathed())
    {
      TOU "The burden would be too great to sheath another weapon.\n");
      return 1;
    }

    TOU "You retrieve "+wep->short()+" and sheath it.\n");
    TRU Name+" retrieves "+wep->short()+" and sheathes it.\n", ({ User }));
    wep->unlock();
    PO->add_sheathed();
    move_object(wep, PO);
    User->add_weight(-((int)wep->query_weight()));
    return 1;
  }
  else {                /* no auto sheath */
    w = (int)wep->query_weight();
    if(!User->add_weight(w))
    {
      TOU "You can't carry that much.\n");
      return 1;
    }
    TOU "You retrieve "+wep->short()+".\n");
    TRU Name+" retrieves "+wep->short()+".\n", ({ User }));
    wep->unlock();
    move_object(wep, User);
    return 1;
  }
}
