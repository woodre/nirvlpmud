/*
 * Guild slave
 * This must be inherited before the guild abstract. (I think)
 */

#include "lib/common.h"

#define V_TESTING

inherit "/obj/guilds/std/interface";

/*
 * heh.  Objects don't need to be static until LPC starts
 * saving memory addresses. Uh.
 */
private object master_obj;
private static string *cmds;
private static int    guild_muffle;

/*
 * ND is rather obsolete... may as well use set_guild_file()
 * code to make it autoload-free. [GI]
 */
status id(string str)
{
  return (str=="guild_object" || str=="ND" || str == "GI" ||
          str=="guild_slave");
}

/*
 * load_me() is an lfun in the guild abstract object which returns
 * this_object() - avoid an unnecessary call [ok, this is
 * rather ridiculous optimization :^)
 */
status load_master()
{
  if(!master_obj)
  {
    string d;
    if(!(master_obj=find_object(d=query_dir("master"))))
      return ((master_obj = (object)d->load_me()), 1);
  }
}   

void init()
{
  int s;
  if(root()) return;
#ifdef V_TESTING
  tell_v("load_master!\n");
  load_master();
#endif
  if(!cmds)
  {
#ifdef V_TESTING
  tell_v("no Cmds!\n");
  tell_v("REGISTERING\n");
#endif
    cmds = (string*)master_obj->query_cmds();
    master_obj->register(TO);
  }
  s = sizeof(cmds);
  while(s--)
  {
#ifdef V_TESTING
  tell_v("cmd_hooking: "+cmds[s]);
#endif
   if(sscanf(cmds[s],"_%s.c",cmds[s]))
    add_action("cmd_hook", cmds[s]);
  }
}

int cmd_hook(string str)
{
  string xv;
  return (int)call_other(query_dir("cmds")+"_"+(xv=query_verb()),
                         "cmd_"+xv, str);
}

status restore_me()
{
  return restore_object(query_dir("save")+ERN);
}

void save_me()
{
  return save_object(query_dir("save")+ERN);
}

void remove_object()
{
  if(root()) return;
  if(master_obj)
    master_obj->deregister(TO);
}

status get() { return 1; } /* return 1 for cloning */
status drop() { return 1; }

void set_guild_muffle(int x) { guild_muffle = x; }
int query_guild_muffle() { return guild_muffle; }
