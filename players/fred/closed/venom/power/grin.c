#include "../defs.h"

status main(string str, object PO, object User) 
{
  object who;
  if(GHOST) return 0;
  if(!str && PO->query_venomed())
  {
    TOU "You give a large grin showing off rows of pointy "+HIG+"slime"+NORM+" covered teeth.\n");
    TRU User->QN+" grins, showing off rows of pointy "+HIG+"slime"+NORM+" covered teeth.\n", ({ User }));
    return 1;
  }
  if(!str && !PO->query_venomed())
  {
    TOU "You grin evilly.\n");
    TRU User->QN+" grins evilly.\n", ({ User }));
    return 1;
  }
  who = present(str, ENV(User));
  if(PO->query_venomed())
  { 
    if(who && living(who)) 
    {
      if(who == User) return 0;
      TOU "You grin at "+CAP(str)+", showing off rows of pointy teeth.\n");
      tell_object(who, User->QN+" grins at you, showing off rows of pointy teeth.\n");
      TRU User->QN+" grins at "+CAP(str)+", showing off rows of pointy teeth.\n", ({ User, who}));
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
    TOU "You grin evilly at "+CAP(str)+" from afar.\n");
    tell_object(who, User->QN+" grins evilly at you from afar.\n");
    return 1;  
    } 
  }
  if(who && living(who)) 
  {
    if(who == User) return 0;
    TOU "You grin evilly at "+CAP(str)+".\n");
    tell_object(who, User->QN+" grins evilly at you.\n");
    TRU User->QN+" grins evilly at "+CAP(str)+".\n", ({ User, who }));
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
    TOU "You grin evilly at "+CAP(str)+" from afar.\n");
    tell_object(who, User->QN+" grins evilly at you from afar.\n");
    return 1;
  }
  return 1; 
}
