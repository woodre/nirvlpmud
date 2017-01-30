#include "/players/jareel/define.h"
inherit "obj/treasure.c";

      reset(arg){
        if(arg) return;
      
      set_short("A statue of the "+HIW+"Templar Ambassador"+NORM+" Stone the "+HIB+"Defender"+HIW+" of the"+HIB+" Realm"+NORM+"|"+RED+"~ "+BLU+"Ele"+GRN+"men"+HIW+"tal Av"+NORM+GRN+"at"+BLU+"ar"+RED+" ~"+NORM);
      set_alias("statue");
      set_long("\n"+BOLD+
       "A statue of the first player to achieve Legendary status, the Knight of legend, Stone.\n\n"+NORM);
      
      
     }


get() { return 0;
}
