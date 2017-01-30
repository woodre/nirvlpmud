#include "/players/quicksilver/666/include/std.h"

init() {
  object stuff,orb;
  int i;
 
  stuff=all_inventory("players/quicksilver/workroom");
  for(i = 0; i <sizeof(stuff); i++)
        {
           if(stuff[i]->id("orb")) {
              orb=stuff[i];
              break;
           }
        }
   move_object(TP,orb->query_exit());
}
