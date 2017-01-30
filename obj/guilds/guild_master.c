/*
 * Guild master
 * This must be inherited before the guild abstract. (I think)
 */

#include "lib/common.h"

inherit "/obj/guilds/std/interface";

private object *slaves;
private static string *cmds;

/*
 * This should never go off without a player loading it,
 * otherwise the cmds may not be loaded properly.
 */
void reset(int arg)
{
  if(!arg)
  {
    if(!slaves)
      slaves = ({ });
    if(!cmds && object_name(this_object()) != "obj/guilds/guild_master")
    {
#ifdef V_TESTING
  tell_v("getting cmds: "+query_dir("cmds")+"\n");
#endif
      cmds = get_dir(query_dir("cmds")+"_*.c");
    }
  }
}

status query_slave(object ob)
{
  return (member_array(ob, slaves) > -1);
}

status register(object ob)
{
  if(!query_slave(ob))
    return ((slaves += ({ ob })), 1);
}

status deregister(object ob)
{
  int x;
  if((x=member_array(ob,slaves)) > -1)
    return ((slaves -= ({ slaves[x] })), 1);
}

/*
 * Returns # of null slaves purged.
 * I can't imagine why we need this information, but may as well
 * configure it this way.
 */
int purge_slaves()
{
  int    s, cnt;
  object *new;
  s = sizeof(slaves);
  new = ({ });
  while(s--)
  {
    if(objectp(slaves[s]))
      new += ({ slaves[s] });
    else
      cnt ++;
  }
  return cnt;
}

/* Returns # of ppl who heard msg */
int broadcast(string str)
{
  int s, cnt;
  purge_slaves();
  if(s = sizeof(slaves))
  {
    object env;
    while(s--)
      /*
       * query_guild_muffle() is an lfun in the guild_slave obj.
       *
       * We check the environment of the player so we don't send
       * them messages when they're logging in; that's always
       * sorta sketch.
       */
      if(slaves[s] && !slaves[s]->query_guild_muffle() &&
          (env=environment(slaves[s])) && environment(env))
        {
          tell_object(env, str);
          cnt ++;
        }
  }
  return cnt;
}

string * query_cmds() { return cmds; }
