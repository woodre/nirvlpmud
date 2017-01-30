#include "../defs.h"

status main(string str, object PO, object User) 
{
  object who;
  if(GHOST) return 0;
  if(!str && !PO->query_venomed())
  {
    TOU "You laugh.\n");
    TRU User->QN+" laughs.\n", ({ User }));
    return 1;
  }
  if(!str && PO->query_venomed()) 
  {
    TOU "You laugh, flecks of "+HIG+"Greenish Goo"+NORM+" fly from your mouth!\n");
    TRU User->QN+" laughs, flecks of "+HIG+"Greenish Goo"+NORM+" flying from "+User->POS+" mouth!\n", ({ User }));
    return 1;
  }
  who = present(str, ENV(User));
  if(PO->query_venomed())
  {
    if(who && living(who)) 
    {
      if(who == User) return 0;
      tell_object(who, User->QN+" laughs at you, flecks of "+HIG+"Greenish Goo"+NORM+" flying from "+User->POS+" mouth!\n");
      TOU "You laugh at "+CAP(str)+", flecks of "+HIG+"Greenish Goo"+NORM+" fly from your mouth!.\n");
      TRU User->QN+" laughs at "+CAP(str)+", flecks of "+HIG+"Greenish Goo"+NORM+" flying from "+User->POS+" mouth!.\n", ({ User, who }));
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
      TOU "You laugh at "+CAP(str)+" from afar.\n");
      tell_object(who, User->QN+" laughs at you from afar.\n");
      return 1; 
    }
    return 1;
  }
  if(who && living(who)) 
  {
    if(who == User) return 0;
    tell_object(who, User->QN+" laughs at you.\n");
    TOU "You laugh at "+CAP(str)+".\n");
    TRU User->QN+" laughs at "+CAP(str)+".\n", ({ User, who }));
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
    TOU "You laugh at "+CAP(str)+" from afar.\n");
    tell_object(who, User->QN+" laughs at you from afar.\n");
    return 1;
  }
  return 1;
}
