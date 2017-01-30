#include "/players/jareel/define.h"
inherit "obj/treasure.c";

      reset(arg){
        if(arg) return;
      
      set_short("A statue of "+BOLD+RED+"D"+BLK+"ead "+RED+"M"+BLK+"an "+RED+"W"+BLK+"alking..."+BLK+"Bone the "+RED+"L"+BLK+"egendary "+RED+"L"+BLK+"ord of "+RED+"D"+BLK+"arkness"+NORM+RED+NORM);
      set_alias("statue");
      set_long("\n"+BOLD+
       "A statue of the first Vampire to achieve Legendary status, the Legendary Dead Man Bone.\n\n"+NORM);
      
      
     }


get() { return 0;
}
