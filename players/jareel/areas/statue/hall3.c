inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {

     if(arg) return;
     set_light(1);
     short_desc=(BOLD+"The Walk of Legends "+NORM);
     long_desc=
       ""+BRED+BLK+"@@"+NORM+"|"+BRED+BLK+"@@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+GRN+"C"+NORM+BOLD+"X"+BOLD+BLK+"M"+NORM+BLK+BRED+"@"+NORM+"     This is the hallway to the Hall of Legends.  To the west is the \n"+ 
       ""+BRED+BLK+"@"+NORM+HIB+"J"+NORM+"+"+HIK+"B"+NORM+BLK+BRED+"@"+NORM+"     command center for Nirvana's Wild Force "+GRN+"Moss"+NORM+" Ranger, Cooper.  To \n"+
       ""+BRED+BLK+"@"+NORM+HIB+"S"+NORM+"+"+NORM+HIR+"K"+NORM+BLK+BRED+"@"+NORM+"     the east, the stench of death and carnage emanates from Nirvana's \n"+
       ""+NORM+"-"+NORM+"-+D"+BLK+BRED+"@"+NORM+"     second Vampiric legend, Magus.  The hall leads to the south.\n"+
       ""+BRED+BLK+"@@"+NORM+"E"+BLK+BRED+"@@"+NORM+"     \n"+     
       "\n"+
       "E - Entrance/Exit : D - Depository  : "+HIB+"S"+NORM+" - Stone's Room  : "+HIR+"K"+NORM+" - Konya's Room\n"+	
       ""+HIB+"J"+NORM+" - Justin's Room : "+HIK+"B"+NORM+" - Bone's Room : "+GRN+"C"+NORM+" - Cooper's Room : "+BOLD+BLK+"M"+NORM+" - Magus's Room\n\n";
     items = ({
       "","",
       "","",
});

dest_dir = ({
     "/players/jareel/areas/statue/coopers_room.c","west",
     "/players/jareel/areas/statue/magus_room.c","east",
     "/players/jareel/areas/statue/hall2.c","south",
     "/players/jareel/areas/statue/hall4.c","north",
});

}
