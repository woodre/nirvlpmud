#include "../defs.h"

status main(string str, object PO, object User)
{
  int amt;
	
  if(file_name(ENV(User)) != "players/fred/closed/venom/symb_room")
    return 0;
	
  if(!str)
  {
    TOU "Store how many coins?\n");
    return 1;
  }
  sscanf(str, "%d", amt);
  if(amt < 1)
  {
    TOU "You cannot store that amount!\n");
    return 1;
  }
  if(amt > User->query_money())
  {
    TOU "You don't have that much!\n");
    return 1;
  }

  User->add_money(-(amt));
  PO->add_stored_mon(amt);

  TOU "You drop "+amt+" coins into the pool of dark matter.\n"+
      "You now have "+(int)PO->query_stored_mon()+" saved up.\n");

  command("lair_check", User);

  write_file("/players/fred/log/store_coins",
    User->QRN+" "+ctime(time())+" "+amt+" "+(int)PO->query_stored_mon()+"\n");
  command("save", User);
  return 1;
}
