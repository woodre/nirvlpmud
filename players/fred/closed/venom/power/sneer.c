#include "../defs.h"

status main(string str, object PO, object User)
{
  object who;
  if(User->query_ghost()) return 1;
  if(!str)
  {
    tell_object(User, "You sneer.\n");
    TRU User->QN+" sneers.\n", ({ User }));
    return 1;
  }
  who = present(str, ENV(User));
  if(who && living(who)) 
  {
    if(who == User) return 0;
    tell_object(User, "You sneer at "+CAP(str)+".\n");
    TRU User->QN+" sneers at "+CAP(str)+".\n", ({ User, who }));
    tell_object(who, User->QN+" sneers at you.\n");
    return 1;  
  } 
  else 
  {
    who = find_player(str);
    if(!who || who == User || in_editor(who) || who->query_invis() >= User->QL)
      return 0;
    if(who->query_tellblock()) 
    {
      tell_object(User, CAP(str)+" is blocking emotes.\n");
      return 1;
    }
    tell_object(User, "You sneer at "+CAP(str)+" from afar.\n");
    tell_object(who, User->QN+" sneers at you from afar.\n");
    return 1;  
  }
  return 1;
}
