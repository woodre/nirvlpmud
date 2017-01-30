#include "/players/jareel/define.h"
inherit "obj/treasure.c";

      reset(arg){
        if(arg) return;
      
      set_short("A statue of the "+HIK+"Nirvana's Fallen Angel -"+NORM+" Sparkle the "+HIW+"Legendary "+NORM+RED+"A"+HIK+"nti"+HIR+"-"+NORM+RED+"P"+HIK+"aladin"+NORM);
      set_alias("statue");
      set_long("\n"+BOLD+
       "A statue of the first Warrior to achieve Legendary status, the Fallen Angel Sparkle.\n\n"+NORM);
      
      
     }


get() { return 0;
}
