#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{
  object wep, obj;
  int amt;

  if(User->query_ghost()) return 0;
  wep = (object)User->query_weapon();
  if(!str)
  {
    TOU "Transfer what?\n");
    return 1;
  }
  if(!wep)
  {  
    TOU "You don't have a weapon wielded.\n");
    return 1;
  }
  if(!wep->query_charge())
  {
    TOU "Your weapon doesn't seem to have any charges.\n");
    return 1;
  }
  sscanf(str, "%d", amt);
  if(amt < 1)
  {
    TOU "You must use a positive number.\n");
    return 1;
  }
  if(amt < 2)
  {
    TOU "You must transfer a minimum of 2.\n");
    return 1;
  }
  if(amt > wep->query_charge())
  {
    TOU "Your weapon only has "+(int)wep->query_charge()+" charges to use.\n");
    return 1;
  }
  if(!(obj = present("fred_bf_bloodward", environment(User))))
  {
    TOU "There isn't a bloodward here.\n");
    return 1;
  }

  wep->add_charge(-amt);
  obj->add_level(amt/2);  

  TOU "Your "+wep->short()+" begins to pulsate as it's energy\n"+
      "   is absorbed by the bloodward.\n");

  TRU Name+"'s "+wep->query_name()+" begins to pulsate as it's energy.\n"+
           "   is absorbed by the bloodward.\n", ({ User }));

  return 1;
}

