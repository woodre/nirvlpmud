#include "../defs.h"

status main(string str, object PO, object User)
{
  string type_it;

  if(GHOST) return 0;
  if(PO->query_creation() < 1) return 0;

  if(!str)
  { 
    TOU "shapearmor neckguard, cloak, boots, gloves, armor, helmet, or all.\n"); 
    return 1; 
  }

  if(str == "all")
  {
    command("shapearmor neckguard", User);
    command("shapearmor armor", User);
    command("shapearmor boots", User);
    command("shapearmor gloves", User);
    command("shapearmor cloak", User);
    command("shapearmor helmet", User);
    return 1;
  }
  if(str == "neckguard")
  {
    if(PO->check_armors("amulet"))
    {
      TOU "You already have type Amulet worn!\n");
      return 1;
    }
    else
    {
      type_it = "amulet";
    }
  }
  else if(str == "cloak")
  {
    if(PO->check_armors("misc"))
    {
      TOU "You already have type Misc worn!\n");
      return 1;
    }
    else
    {
      type_it = "misc";
    }
  }
  else if(str == "boots")
  {
    if(PO->check_armors("boots"))
    {
      TOU "You already have type Boots worn!\n");
      return 1;
    }
    else
    {
      type_it = "boots";
    }
  }
  else if(str == "gloves")
  {
    if(PO->check_armors("gloves"))
    {
      TOU "You already have type Gloves worn!\n");
      return 1;
    }
    else
    {
      type_it = "gloves";
    }
  }
  else if(str == "armor")
  {
    if(PO->check_armors("armor"))
    {
      TOU "You already have type Armor worn!\n");
      return 1;
    }
    else
    {
      type_it = "armor";
    }
  }
  else if(str == "helmet")
  {
    if(PO->check_armors("helmet"))
    {
      TOU "You already have type Helmet worn!\n");
      return 1;
    }
    else
    {
      type_it = "helmet";
    }
  }
  else
  {  
    TOU "shapearmor neckguard, cloak, gloves, boots, helmet, armor, or all.\n");
    return 1; 
  }
  
  if(type_it == "armor")
  {
    if(PO->query_mp() < 40)
    {
      TOU "You lack the "+HIW+"Dark Matter"+NORM+" to do that.\n");
      return 1;
    }
    else 
      PO->add_mp(-40);
  }
  else
  {
    if(PO->query_mp() < 20)
    {
      TOU "You lack the "+BOLD+"Dark Matter"+NORM+" to do that.\n");
      return 1;
    }
    else 
      PO->add_mp(-20);
  }

  TOU "You concentrate and force your symbiote to create "+str+" from its "+BOLD+"Dark Matter"+NORM+".\n");

  TRU HIW+"Glistening black armor forms on "+User->QN+"."+NORM+"\n");

  PO->add_sh_armors(type_it);
  return 1;
}
