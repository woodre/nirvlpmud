#include "../defs.h"

status main(string str, object PO, object User)
{
  if(PO->query_venomed())
  {
    TOU "Change to normal before you leave the guild.\n");
    return 1;
  }
  if(User->QL > 19)
  {
    TOU "Dest this object, you're a wiz.\n");
    return 1;
  }
  
  TOU "\n\nYou take hold of the symbiote and tear it from your spine!\n"+
      "\n          YOU HEAR A MENTAL SCREAM TEAR INTO YOUR HEAD!!!\n"+
      "A dark thick blood gushes outward and you feel yourself\n"+
      "sink into dark oblivion.\n\n");

  TOU "\n\n                      You feel very alone.....\n");

  write_file("/players/fred/closed/venom/logs/LEAVE", ctime(time())+
             "   "+HIR+User->QRN+NORM+" [L "+
             User->QL+"+"+User->QEL+"] \n"+NORM);

  User->destruct_this_shadow();
  
  rm("/players/fred/closed/venom/member/"+User->QRN+".o");
  
  User->set_guild_name(0);
  User->set_guild_file(0);
	
  if(User->query_exp() > 5885)
  {
    User->add_exp(-((int)User->query_exp() - 5885));
    User->set_level(5);
    User->set_extra_level(0);
  }
  User->save_me();
  User->reset();
  destruct(PO);
  return 1;
}
