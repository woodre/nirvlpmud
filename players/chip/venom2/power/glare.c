#include "/players/fred/closed/venom/defs.h"

status main(string str, object PO, object User) 
{
  object who;
  if(GHOST || !str) return 0;
  who = present(str, ENV(User));
  if(PO->query_venomed())
  {  
    if(who && living(who)) 
    {
      if(who == User) return 0;
      TOU "You give an angry glare at "+CAP(str)+".\n");
      tell_object(who, User->QN+"'s cold white eye's glare at you menacingly.\n");
      TRU User->QN+"'s cold white eye's glare at "+CAP(str)+".\n", ({ User, who}));
      return 1;
    }
    else 
    {
      who = find_player(str);
      if(!who || who == User || in_editor(who) || who->query_invis() >= User->QL)
        return 0;
      if(who->query_tellblock()) 
      {
        TOU CAP(str)+" is blocking emotes.\n");
        return 1;
      }
      TOU "You give an angry glare at "+CAP(str)+" from afar.\n");
      tell_object(who, User->QN+" gives you an angry glare from afar.\n");
      return 1;
    }
    return 1;
  }
  if(who && living(who)) 
  {
    if(who == User) return 0;
    TOU "You glare stonily at "+CAP(str)+".\n");
    tell_object(who, User->QN+" glares at you stonily.\n");
    TRU User->QN+" glares at "+CAP(str)+" stonily.\n", ({ User, who }));
    return 1;
  }
  else 
  {
    who = find_player(str);
    if(!who || who == User || in_editor(who) || who->query_invis() >= User->QL)
      return 0;
    if(who->query_tellblock()) 
    {
      TOU CAP(str)+" is blocking emotes.\n");
      return 1;
    }
    TOU "You glare stonily at "+CAP(str)+" from afar.\n");
    tell_object(who, User->QN+" glares stonily at you from afar.\n");
  }
  return 1;
}