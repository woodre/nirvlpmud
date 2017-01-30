#include "../defs.h"

status main(string str, object PO, object User)
{
  if(GHOST) return 0;
  if(User->QL < 19) return 0;

  if(PO->query_stored_mon() > 1000000 && 
     PO->query_stored_mp()  > 100000  &&
     PO->query_stored_sp()  > 100000)
  {
    TOU BOLD+"                    <<<< LAIR >>>>"+HIR+"\n\n\n"+
        "    Your lair is ready now.  All you need to do is "+HIW+"'place'"+HIR+" it where\n"+
        "  you want it hidden.  Remember it cannot go into the main village\n"+
        "  and a few other places, which you will know if you try."+NORM+HIW+"\n\n\n"+
        "                    <<<< LAIR >>>>"+NORM+"\n");

    PO->add_stored_mon(-1000000);
    PO->add_stored_mp(-100000);
    PO->add_stored_sp(-100000);
    PO->set_has_lair(1);

    write_file("/players/fred/log/lair",
      ctime(time())+" "+User->QN+" received their lair.\n");
    return 1;      
  }
  return 0;
}
