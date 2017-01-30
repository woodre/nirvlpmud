#include "../DEFS.h"


status main(string str)
{
   TP->unset_invs_sp();
   IPTP->set_shadows(0);
   IPTP->save_me();
   write("You have left the shadows.\n");
   return 1;
}
