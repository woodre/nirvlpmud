#include "../defs.h"

status main(string str, object PO, object User)
{
  int x, y, z;
  if(GHOST) return 0;

  if(str != "control" || str != "combat" || str != "creation")
  {
    TOU "You are able to raise <control> <combat> or <creation>.\n");
    return 1;
  }
  if(str == "control")
  {
    x = (int)PO->query_control();
    if(x == 8)
    {
      TOU "You can't raise "+str+" any higher.\n");
      return 1;
    } 
    y = (int)PO->query_glvl_cost(x);
    if(z = ((int)PO->query_gexp()) < y)
    {  
      TOU "You don't have enough guild exp to raise "+str+".\n");
      return 1;
    }
    PO->add_control(1);
    PO->add_gexp(-y);
    PO->add_glvl(1);
    User->add_guild_exp(y);
    return 1;
  }
  if(str == "combat")
  {
    x = (int)PO->query_combat();
    if(x == 8)
    {
      TOU "You can't raise "+str+" any higher.\n");
      return 1;
    } 
    y = (int)PO->query_glvl_cost(x);
    if(z = ((int)PO->query_gexp()) < y)
    {  
      TOU "You don't have enough guild exp to raise "+str+".\n");
      return 1;
    }
    PO->add_combat(1);
    PO->add_gexp(-y);
    PO->add_glvl(1);
    User->add_guild_exp(y);
    return 1;
  }   
  if(str == "creation")
  {
    x = (int)PO->query_creation();
    if(x == 8)
    {
      TOU "You can't raise "+str+" any higher.\n");
      return 1;
    } 
    y = (int)PO->query_glvl_cost(x);
    if(z = ((int)PO->query_gexp()) < y)
    {  
      TOU "You don't have enough guild exp to raise "+str+".\n");
      return 1;
    }
    PO->add_creation(1);
    PO->add_gexp(-y);
    PO->add_glvl(1);
    User->add_guild_exp(y);
    return 1; 
  }
  return 1;
}
