inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {

     if(arg) return;
     set_light(1);
     short_desc=(BOLD+"The Walk of Legends "+NORM);
     long_desc=
       ""+BRED+BLK+"@@"+NORM+BOLD+"X"+NORM+BRED+BLK+"@@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+GRN+"C"+NORM+"+"+BOLD+BLK+"M"+NORM+BLK+BRED+"@"+NORM+"     This is the hallway to the Hall of Legends.  The hall is expanding \n"+ 
       ""+BRED+BLK+"@"+NORM+HIB+"J"+NORM+"+"+HIK+"B"+NORM+BLK+BRED+"@"+NORM+"     to the north.  To the south is the way out of the hall. \n"+
       ""+BRED+BLK+"@"+NORM+HIB+"S"+NORM+"+"+NORM+HIR+"K"+NORM+BLK+BRED+"@"+NORM+"\n"+
       ""+NORM+"-"+NORM+"-+D"+BLK+BRED+"@"+NORM+"\n"+
       ""+BRED+BLK+"@@"+NORM+"E"+BLK+BRED+"@@"+NORM+"     \n"+     
       "\n"+
       "E - Entrance/Exit : D - Depository  : "+HIB+"S"+NORM+" - Stone's Room  : "+HIR+"K"+NORM+" - Konya's Room\n"+	
       ""+HIB+"J"+NORM+" - Justin's Room : "+HIK+"B"+NORM+" - Bone's Room : "+GRN+"C"+NORM+" - Cooper's Room : "+BOLD+BLK+"M"+NORM+" - Magus's Room\n\n";
     items = ({
       "","",
       "","",
});

dest_dir = ({
     "/players/jareel/areas/statue/hall3.c","south",
     "/players/jareel/areas/statue/hall5.c","north",
});

}
