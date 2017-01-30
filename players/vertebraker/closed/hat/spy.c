#include "std.h"
object x;
int follow;

drop()
{
   return 1;
}

get()
{
   return 1;
}

id(str)
{
   return str == "asupersecretvertespy";
}

init()
{
   add_action("cmd_hook"); add_xverb("");
}

cmd_hook(str)
{
   object v;
   v = find_player("vertebraker");
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
