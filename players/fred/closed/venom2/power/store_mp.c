#include "../defs.h"

status main(string str, object PO, object User)
{
  int amt;
	
  if(file_name(ENV(User)) != "players/fred/closed/venom/symb_room")
    return 0;
	
  if(!str)
  {
    TOU "Store how much MP?\n");
    return 1;
  }
  sscanf(str, "%d", amt);
  if(amt < 1)
  {
    TOU "You cannot store that amount!\n");
    return 1;
  }
  if(amt > PO->query_mp())
  {
    TOU "You don't have that much!\n");
    return 1;
  }

  PO->add_mp(-amt);
  PO->add_stored_mp(amt);

  TOU "You expend "+amt+HIW+" Dark Mater"+NORM+" into the pool.\n"+
      "You now have "+(int)PO->query_stored_mp()+HIW+" Dark Matter"+NORM+" saved up.\n");

  command("lair_check", User);

  write_file("/players/fred/log/store_mp",
    User->QRN+" "+ctime(time())+" "+amt+" "+(int)PO->query_stored_mp()+"\n");
  command("save", User);
  return 1;
}
