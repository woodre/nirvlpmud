inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {

     if(arg) return;
     set_light(1);
     short_desc=(BOLD+"The Walk of Legends "+NORM);
     long_desc=
       ""+BRED+BLK+"@@"+NORM+"|"+BRED+BLK+"@@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+GRN+"C"+NORM+"+"+BOLD+BLK+"M"+NORM+BLK+BRED+"@"+NORM+"     This is the hallway in the Hall of Legends.  To the west \n"+ 
       ""+BRED+BLK+"@"+NORM+HIB+"J"+NORM+"+"+HIK+"B"+NORM+BLK+BRED+"@"+NORM+"     resides Nirvana's first Legend, Stone.  To the east rests \n"+
       ""+BRED+BLK+"@"+NORM+HIB+"S"+NORM+BOLD+"X"+NORM+HIR+"K"+NORM+BLK+BRED+"@"+NORM+"     Nirvana's Badass Legend, Konya.  The hall continues to the \n"+
       ""+NORM+"-"+NORM+"-+D"+BLK+BRED+"@"+NORM+"     north and south.\n"+
       ""+BRED+BLK+"@@"+NORM+"E"+BLK+BRED+"@@"+NORM+"     \n"+     
       "\n"+
       "E - Entrance/Exit : D - Depository  : "+HIB+"S"+NORM+" - Stone's Room  : "+HIR+"K"+NORM+" - Konya's Room\n"+	
       ""+HIB+"J"+NORM+" - Justin's Room : "+HIK+"B"+NORM+" - Bone's Room : "+GRN+"C"+NORM+" - Cooper's Room : "+BOLD+BLK+"M"+NORM+" - Magus's Room\n\n";
     items = ({
       "","",
       "","",
});

dest_dir = ({
     "/players/jareel/areas/statue/stones_room.c","west",
     "/players/jareel/areas/statue/konyas_room.c","east",
     "/players/jareel/areas/statue/enter.c","south",
     "/players/jareel/areas/statue/hall2.c","north",
});

}
