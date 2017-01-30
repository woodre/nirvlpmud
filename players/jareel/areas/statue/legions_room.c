inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
   
     if(arg) return;
     set_light(1);
     short_desc=("Magus's personal "+RED+"Coffin"+NORM);
     long_desc=
       ""+BRED+BLK+"@@@@@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+GRN+"C"+NORM+"+"+NORM+BOLD+"X"+NORM+BLK+BRED+"@"+NORM+"\n"+ 
       ""+BRED+BLK+"@"+NORM+HIB+"J"+NORM+"+"+HIK+"B"+NORM+BLK+BRED+"@"+NORM+"     Magus's personal "+RED+"Hell"+NORM+" is currently in symbiosis.\n"+
       ""+BRED+BLK+"@"+NORM+HIB+"S"+NORM+"+"+NORM+HIR+"K"+NORM+BLK+BRED+"@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+"-+D"+BLK+BRED+"@"+NORM+" \n"+
       ""+BRED+BLK+"@@"+NORM+"E"+BLK+BRED+"@@"+NORM+"\n"+     
       "\n"+
       "E - Entrance/Exit : D - Depository  : "+HIB+"S"+NORM+" - Stone's Room  : "+HIR+"K"+NORM+" - Konya's Room\n"+	
       ""+HIB+"J"+NORM+" - Justin's Room : "+HIK+"B"+NORM+" - Bone's Room : "+GRN+"C"+NORM+" - Cooper's Room : "+BOLD+BLK+"M"+NORM+" - Magus's Room\n\n";
     items = ({
       "plaque","Magus's Room",
       "wall","The room is empty except a small plaque",
});

dest_dir = ({
     "/players/jareel/areas/statue/hall3.c","west",
});

}
