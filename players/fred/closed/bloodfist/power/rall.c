#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object r, *env;
  int a,c,w,d,e;
  if(User->query_ghost()) return 0;

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


