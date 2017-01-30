#include "../defs.h"

status main(string str, object PO, object User)
{
  int amt;
	
  if(GHOST) return 0;
  if(PO->query_control() < 5) return 0;

  if(!str)
  { 
    TOU "heal <amount>  range of 5-"+((int)PO->query_control() * 5)+"\n");
    return 1; 
  }
	
  sscanf(str, "%d", amt);
  if(!amt)
  { 
    TOU "heal <amount>  range of 5-"+((int)PO->query_control() * 5)+"\n");
    return 1; 
  }
  if(amt < 5)
  { 
    TOU "heal <amount>  range of 5-"+((int)PO->query_control() * 5)+"\n");
    return 1; 
  }
  if(amt > (int)PO->query_control() * 5)
  { 
    TOU "heal <amount>  range of 5-"+((int)PO->query_control() * 5)+"\n");
    return 1; 
  }
  if(User->query_sp() < amt)
  { 
    TOU "You lack the energy to perform a heal.\n"); 
    return 1; 
  }

  User->add_spell_point(-amt);
  User->add_hit_point(amt);
  PO->add_mp(-(amt/6));

  TOU PO->query_color()+"(heal)"+NORM+"  You concentrate and will your symbiote to heal your wounds.\n"+
      "             "+PO->query_color()+"HPS: "+NORM+User->query_hp()+"/"+User->query_mhp()+"\n");

  TRU User->QN+" closes "+User->POS+" eyes and "+User->POS+" wounds close.\n", ({ User }));
  return 1;
}
