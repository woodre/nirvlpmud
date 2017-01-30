#include "../defs.h"

status main(string str, object PO, object User)
{
  object poison, next;
  string a,b;

  if(GHOST) return 0;
  if(PO->query_control() < 1) return 0;

  if(User->query_sp() < 50)
  {
    TOU PO->query_color()+"You lack the energy to do that."+NORM+"\n");
    return 1;
  }

  TOU PO->query_color()+"A "+NORM+HIW+"Dark Matter Tentacle"+NORM+PO->query_color()+" dives beneath your skin."+NORM+"\n");
  
  poison = first_inventory(User);
  
  while(poison) 
  {
    next = next_inventory(poison);
    if(sscanf(file_name(poison),"%spoison%s",a,b) == 2 ||
			poison->id("poison")) 
    {
      TOU HIG+"Poison is destroyed"+NORM+BOLD+"..."+NORM+"\n");
      destruct(poison);
    }
    poison = next;
  }
  User->add_spell_point(-50);
  return 1;
}


