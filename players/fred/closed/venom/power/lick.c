#include "../defs.h"

status main(string str, object PO, object User) 
{
  object who;
  if(GHOST || !str) return 0;
  who = present(str, ENV(User));
  if(str == "boltar" && (string)User->query_gender() !="female") return 0;
  if(PO->query_venomed())
  {  
    if(who && living(who)) 
    {
      if(who == User) return 0;
      TOU "You lick "+CAP(str)+", drawing a thin line of "+HIR+"blood"+NORM+" on their cheek.\n");
      tell_object(who, User->QN+"'s tongue lashes out, drawing a thin line of "+HIR+"blood"+NORM+" on your cheek.\n");
      TRU User->QN+"'s tongue lashes out at "+CAP(str)+", drawing a thin line of "+HIR+"blood"+NORM+" on their cheek.\n", ({ User, who }));
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
      TOU "You lick "+CAP(str)+" from afar.\n");
      tell_object(who, User->QN+" licks you from afar.\n");
      return 1; 
    }
    return 1;
  }
  if(who && living(who)) 
  {
    if(who == User) return 0;
    TOU "You lick "+CAP(str)+".\n");
    tell_object(who, User->QN+" licks you.\n");
    TRU User->QN+" licks "+CAP(str)+".\n", ({ User, who }));
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
    TOU "You lick "+CAP(str)+" from afar.\n");
    tell_object(who, User->QN+" licks you from afar.\n");
    return 1;
  }
  return 1;
}
