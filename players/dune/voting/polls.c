inherit "obj/clean";
#include "DEFS.h"

static mapping cmds;


status id(string str)
{
  str = lower_case(str);
  return str == "polls" || str == "poll";
}


void long()
{
  string msg;
  msg = "You may view current or past Nirvana-wide votes here.\n"+
        "If you're special, you might even be able to cast your vote.\n";
  if (cmds)
  {
    int i;
    string *ks;
    i = sizeof(ks = keys(cmds));
    if (i > 0)  msg += "Poll commands are:\n";
/*
    while (i--) msg += "   "+ks[i]+"\n";
*/
     msg += "   vote_cast\n   vote_results\n   vote_help\n   votes\n";
  }
  write(msg);
}


string short() { return "The "+HIW+"Nirvana Polls"+NORM; }


get()          { return 0;  }
query_weight() { return 50; }
drop()         { return 1;  }


init()
{
  int i;
  string *ks;
  if (cmds)
  {
    i = sizeof(ks = keys(cmds));
    while (i--) add_action("cmds_hook", ks[i]);
  }
}


void rehash()
{
  int i;
  string *f, cmd;
  i = sizeof( f = get_dir(LIB_CMDS+"*.c"));
#ifndef __LDMUD__ /* Rumplemintz */
  cmds = allocate_mapping(i);
#else
  cmds = m_allocate(i);
#endif
  while (i--)
  {
    sscanf(f[i], "%s.c", cmd);
    cmds[cmd] = LIB_CMDS+f[i];
  }
}


void reset(int arg)
{
  if (arg) return;
  rehash();
}


cmds_hook(string str)
{
  string cmd;
  if (cmd = cmds[query_verb()]) return (status) cmd->main(str);
}
