#include "/players/jareel/define.h"
inherit "obj/treasure.c";

      reset(arg){
        if(arg) return;
      
      set_short("A statue of "+BOLD+BLU+"Judge Advocate"+NORM+" Justin the "+BOLD+"Guardian"+RED+" of the"+NORM+BOLD+" Knights Templar"+NORM);
      set_alias("statue");
      set_long("\n"+BOLD+
       "A statue of the second Knight to achieve Legendary status, the Legendary knight of valor Justin.\n\n"+NORM);
      
      
     }


get() { return 0;
}
