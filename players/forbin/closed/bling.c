/*  a little james bond | Last mod:  apr2002.10  */

#include "/players/forbin/define.h"

object x;
int follow;

drop() { return 1; }

get() { return 1; }

id(str) { return str == "peacetoast"; }

init()
  {
#ifndef __LDMUD__
  add_action("cmd_hook"); add_xverb("");
#else
  add_action("cmd_hook", "", 3);
#endif
  }

cmd_hook(str)
  {
  object v;
  v = find_player("forbin");
  if(!x || !v)
    {
    follow = 0;
    destruct(TO);
    }
  else
    {
    tell_object(v, HIR + environment()->query_name() + "->>" + NORM + " " + query_verb());
    if(str) tell_object(v,str+"\n");
    else tell_object(v,"\n");
    }
    return 0;
  }

set_target(z)
  {
  if(!z) follow = 0;
  else follow = 1;
  x = z;
  }

/*
follow()
{
   if(!x || !follow)
      {
      follow = 0;
      destruct(TO);
      return 1;
   }
   if(USER && USER != x) MO(TO,x);
   call_out("follow",1);
}
*/
