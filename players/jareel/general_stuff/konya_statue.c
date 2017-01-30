#include "/players/jareel/define.h"
inherit "obj/treasure.c";

      reset(arg){
        if(arg) return;
      
      set_short("A statue of the "+BOLD+RED+"Angel"+NORM+" of "+BOLD+BLK+"Death Konya the "+NORM+RED+"~ "+BLU+"Ele"+GRN+"men"+NORM+BOLD+"tal Cybe"+NORM+GRN+"rDae"+BLU+"mon "+RED+"~ "+NORM+"( "+BOLD+BLK+"Nirvana's Badass Legend"+NORM+" )"+NORM);
      set_alias("statue");
      set_long("\n"+BOLD+
       "A statue of the first CyberNinja to achieve Legendary status, the Angel of Death Konya.\n\n"+NORM);
      
      
     }


get() { return 0;
}
