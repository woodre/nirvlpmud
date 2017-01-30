#include "../defs.h"

status main(string str, object PO, object User)
{
  int expcost,minexp,woo;

  if(PO->query_glvl() > 15)
  { 
    TOU "You are already maxed.\n"); 
    return 1; 
  }
  if(!str)
  { 
    TOU "Convert how many experience points?\n"); 
    return 1; 
  }
  sscanf(str, "%d", woo);
  if(User->QL > 19) return 1;
	
  if(woo < 1)
  {
    TOU "You must convert a positive number of experience points.\n");
    return 1; 
  }
	
  expcost = woo;
  if(User->QEL < 1 && User->QL < 21)
    minexp = (int)User->query_exp() - (int)call_other("room/adv_guild", "get_next_exp",
	((int)User->QL - 1));
	
  if(User->QEL > 0 && User->QL < 21)
    minexp = (int)User->query_exp() - (int)call_other("room/exlv_guild", "get_next_exp",
	((int)User->QEL - 1));
	
  if(expcost > minexp) 
  {
    TOU "You do not have enough available experience to convert.\n");
    return 1;
  }
	
  User->add_exp(-woo);
  write("You convert "+str+" experience towards your Symbiotic Control.\n");
	
  PO->adv_check(woo);
  return 1;
}
