#include "../defs.h"

status main(string str, object PO, object User)
{
  int amt;
	
  if(file_name(ENV(User)) != "players/fred/closed/venom/symb_room")
    return 0;
	
  if(!str)
  {
    TOU "Store how many sps?\n");
    return 1;
  }
  sscanf(str, "%d", amt);
  if(amt < 1)
  {
    TOU "You cannot store that amount!\n");
    return 1;
  }
  if(amt > User->query_sp())
  {
    TOU "You don't have that much!\n");
    return 1;
  }

  User->add_spell_point(-amt);
  PO->add_stored_sp(amt);

  TOU "You expend "+amt+" spell energy into the pool.\n"+
      "You now have "+(int)PO->query_stored_sp()+" saved up.\n");

  command("lair_check", User);

  write_file("/players/fred/log/store_sps",
    User->QRN+" "+ctime(time())+" "+amt+" "+(int)PO->query_stored_sp()+"\n");
  command("save", User);
  return 1;
}
