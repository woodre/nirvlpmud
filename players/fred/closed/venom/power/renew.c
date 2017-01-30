#include "../defs.h"

status main(string str, object PO, object User)
{
  if(User->QL < 20 && (string)User->QRN != "toy") return 1;
  TOU "You give yourself 300 mp.\n");
  PO->add_mp(300);
  return 1;
}
