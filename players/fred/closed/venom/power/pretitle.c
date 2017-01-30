#include "../defs.h"

status main(string str, object PO, object User)
{
  if(PO->query_venomed())
  {
    TOU	"You cannot change your pretitle while you are "+CAP((string)PO->query_symbiote())+"!\n");
    return 1;
  }
  return 0;
}
