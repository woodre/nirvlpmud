#include "/players/jareel/define.h"
inherit "obj/treasure.c";

      reset(arg){
        if(arg) return;
      
      set_short("A statue of Breeti "+BOLD+"the Legend"+NORM);
      set_alias("statue");
      set_long("\n"+BOLD+
       "A statue of the first Polymorph to achieve Legendary status, the Legendary Poly Breeti.\n\n"+NORM);
      
      
     }


get() { return 0;
}
