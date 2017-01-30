#include "../defs.h"

status main(string str, object PO, object User)
{
  write_file("/players/fred/log/venom_xp",
    "Logout: "+ctime(time())+"  "+User->QRN+
    "  [Level  "+User->QL+"+"+User->QEL+"] "+(int)PO->query_hb_count()+" "+
    ""+User->query_exp()+"\n");

  if((string)PO->query_oldtitle())
  {
    User->set_title(PO->query_oldtitle());
    PO->set_oldtitle(0);
  }

  if((string)PO->query_oldalign())
  {
    User->set_al_title(PO->query_oldalign());
    PO->set_oldalign(0);
  }

  if((string)PO->query_oldpretitle())
  {
    User->set_pretitle(PO->query_pretitle());
    PO->set_oldpretitle(0);
  }

  if(User->query_attack())
  {
    TOU "You cannot quit out while in combat!\n");
    return 1;
  }
  command("save", User);
  return 0;
}
