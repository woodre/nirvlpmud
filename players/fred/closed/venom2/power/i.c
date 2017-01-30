#include "../defs.h"

status main(string str, object PO, object User)
{
  object woo,woo2;
  int i;
  i = 1;
  woo = first_inventory(User);
	
  TOU BOLD+"   ________________ [ Symbiote Inventory ] ________________"+NORM+"\n"+
      "   Item: \n");
	
  while(woo)
  {
    woo2 = next_inventory(woo);
    if(woo->short())
    {
      if(i < 10)
      {
        TOU "["+HIR+"0"+i+NORM+"]  "+woo->short()+"  "); 
      }
      else
      { 
        TOU "["+HIR+i+NORM+"]  "+woo->short()+"  ");  
      }
      if(woo->armor_class()) 
      {
        TOU "["+HIR+woo->query_type()+NORM+"]\n"); 
      }
      else if(woo->weapon_class())
      {
        TOU "["+HIR+"Weapon"+NORM+"]\n"); 
      }
      else
      {
        TOU "\n"); 
      }
      
      i++;
    }
    woo = woo2;
  }
  TOU "\nYou are carrying: "+User->query_pct_weight()+"% of max.\n");
  return 1;
}
