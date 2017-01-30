inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {

     if(arg) return;
     set_light(1);
     short_desc=(HIW+"The Walk of Legends"+NORM);
     long_desc=
       ""+BRED+BLK+"@@"+NORM+"|"+BRED+BLK+"@@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+RED+"E"+NORM+"+"+BRED+BLK+"@@"+NORM+"     This is the Dervish hallway in the Hall of Legends.  To the west\n"+ 
       ""+BRED+BLK+"@"+NORM+GRN+"H"+NORM+"+"+HIK+"B"+NORM+BRED+BLK+"@"+NORM+"     is the first Dervish to achive legendary status Prestion.  To the \n"+
       ""+BRED+BLK+"@"+NORM+RED+"P"+NORM+BOLD+"X"+NORM+RED+"H"+BRED+BLK+"@"+NORM+"     the east is the second Dervish to reach +100\n"+
       ""+BLK+BRED+"@"+NORM+HIY+"T"+NORM+"+"+NORM+HIB+"S"+NORM+BRED+BLK+"@"+NORM+"     the legend Humble.  The hall is coverd\n"+
       ""+BRED+BLK+"@"+NORM+HIY+"B"+NORM+"+"+NORM+HIK+"H"+NORM+BRED+BLK+"@"+NORM+"     in sand.\n"+     
       "\n"+
       ""+HIY+"B"+NORM+" - Breeti's Room : "+HIK+"H"+NORM+" - Hardly's Room : "+HIY+"T"+NORM+" - Tweak's Room : "+HIB+"S"+NORM+" - Sparkle's Room\n"+	
       ""+RED+"P"+NORM+" - Preston's Room : "+RED+"H"+NORM+" - Humble's Room  :"+GRN+"H"+NORM+" - Hoyle's Room : "+RED+"B"+NORM+" - Bleh's Room\n"+
""+RED+"R"+NORM+" - Entreri's Room\n";


     items = ({
       "","",
       "","",
});

dest_dir = ({
     "/players/jareel/areas/statue/prestons_room.c","west",
     "/players/jareel/areas/statue/hall6.c","south",
    /* "/players/jareel/areas/statue/hall8.c","north",*/
     "/players/jareel/areas/statue/humbles_room.c","east",
     
});

}
