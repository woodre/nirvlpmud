#include "../defs.h"

status main(string str, object PO, object User) 
{
  object *symb, venom;  
  int x;
  if(User->QL < 20) return 0;

  symb = users();
 
  for(x=0; x < sizeof(symb); x++)
  {
    venom = present("venom_object", symb[x]);

    if(venom)
    {
      tell_object(symb[x],
        HIR+CAP((string)venom->query_symbiote())+HIW+NORM+" tells you: \""+str+"\".\n");      
    }
  }
  return 1;
}
