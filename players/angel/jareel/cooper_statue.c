#include "/players/jareel/define.h"
inherit "obj/treasure.c";

      reset(arg){
        if(arg) return;
      
      set_short("A statue of Cooper "+BOLD+"the Legendary"+NORM+RED+" WILD"+BLU+" FORCE"+GRN+" MOSS"+NORM+RED+"   ~  "+BLU+"Ele"+GRN+"men"+NORM+BOLD+"tal Ra"+NORM+GRN+"ng"+BLU+"er"+NORM+RED+" ~"+NORM);
      set_alias("statue");
      set_long("\n"+BOLD+
       "A statue of the first Ranger to achieve Legendary status, the spandex wearing Cooper.\n\n"+NORM);
      
      
     }


get() { return 0;
}
