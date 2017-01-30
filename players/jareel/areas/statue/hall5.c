inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {

     if(arg) return;
     set_light(1);
     short_desc=(HIW+"The Walk of Legends"+NORM);
     long_desc=
       ""+BRED+BLK+"@@"+NORM+"|"+BRED+BLK+"@@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+RED+"E"+NORM+"+"+BRED+BLK+"@@"+NORM+"     This is the hallway to the Hall of Legends.  To the west is \n"+ 
       ""+BRED+BLK+"@"+NORM+GRN+"H"+NORM+"+"+HIK+"B"+NORM+BRED+BLK+"@"+NORM+"     the morphic lair of the first Polymorph legend Breeti.  This\n"+
       ""+BRED+BLK+"@"+NORM+RED+"P"+NORM+"+"+NORM+RED+"H"+BRED+BLK+"@"+NORM+"     section of the hall is still undergoing building.\n"+
       ""+BLK+BRED+"@"+NORM+HIY+"T"+NORM+"+"+HIB+"S"+NORM+BRED+BLK+"@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+HIY+"B"+NORM+BOLD+"X"+NORM+HIK+"H"+NORM+BRED+BLK+"@"+NORM+"     \n"+     
       "\n"+
       ""+HIY+"B"+NORM+" - Breeti's Room : "+HIK+"H"+NORM+" - Hardly's Room : "+HIY+"T"+NORM+" - Tweak's Room : "+HIB+"S"+NORM+" - Sparkle's Room\n"+	
       ""+RED+"P"+NORM+" - Preston's Room : "+RED+"H"+NORM+" - Humble's Room  :"+GRN+"H"+NORM+" - Hoyle's Room : "+RED+"B"+NORM+" - Bleh's Room\n"+
""+RED+"R"+NORM+" - Entreri's Room\n";


     items = ({
       "","",
       "","",
});

dest_dir = ({
     "/players/jareel/areas/statue/breeti_room.c","west",
     "/players/jareel/areas/statue/hall4.c","south",
     "/players/jareel/areas/statue/hall6.c","north",
     "/players/jareel/areas/statue/hardlys_room.c","east",
     
});

}
