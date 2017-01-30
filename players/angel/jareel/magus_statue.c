#include "/players/jareel/define.h"
inherit "obj/treasure.c";

      reset(arg){
        if(arg) return;
      
      set_short("A statue of Magus "+BOLD+"the Malefactor Legend of Macabre"+NORM);
      set_alias("statue");
      set_long("\n"+BOLD+
       "A statue of the second Vampire to achieve Legendary status, the Legendary Demon of darkness Magus.\n\n"+NORM);
      
      
     }


get() { return 0;
}
