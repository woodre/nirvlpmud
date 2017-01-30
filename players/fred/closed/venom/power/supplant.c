#include "../defs.h"

status main(string str, object PO, object User)
{
  if(!PO->query_venomed()) return 1;
  if(PO->query_uncovered())
  {
    PO->set_uncovered(0);
    TOU "You concentrate briefly and feel the symbiote regrow over your face.\n");
    TRU	"You watch as black ooze slowly grows back over "+User->QRN+"'s face.\n", ({ User }));
    return 1;
  }
  else
  {
    PO->set_uncovered(1);
    TOU "You feel a tingling as the symbiote separates itself from around your head.\n");
    TRU	"The black ooze around "+CAP((string)PO->query_symbiote())+"'s head peels back to reveal "+User->QRN+".\n", ({ User }));
    return 1;
  }
  return 1;
}
