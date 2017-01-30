inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {

     if(!present("tablet"))  {
       MOCO("/players/jareel/general_stuff/tablet.c"),this_object()); }
     if(arg) return;
     set_light(1);
     short_desc=(BOLD+"Hall of Legends"+NORM);
     long_desc=
       ""+BRED+BLK+"@@"+NORM+"|"+BRED+BLK+"@@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+GRN+"C"+NORM+"+"+BOLD+BLK+"M"+NORM+BLK+BRED+"@"+NORM+"     This is the tablet room of the Hall of Legends.  The room\n"+ 
       ""+BRED+BLK+"@"+NORM+HIB+"J"+NORM+"+"+HIK+"B"+NORM+BLK+BRED+"@"+NORM+"     is made of a dark stone similar to onyx.  A passage leads\n"+
       ""+BRED+BLK+"@"+NORM+HIB+"S"+NORM+"+"+HIR+"K"+NORM+BLK+BRED+"@"+NORM+"     out to the east.  There is a large stone tablet resting on\n"+
       ""+NORM+"-"+NORM+BOLD+"X"+NORM+"+D"+BLK+BRED+"@"+NORM+"     the floor in the center of the room.\n"+
       ""+BRED+BLK+"@@"+NORM+"E"+BLK+BRED+"@@"+NORM+"\n"+
       "\n"+
       "E - Entrance/Exit : D - Depository  : "+HIB+"S"+NORM+" - Stone's Room  : "+HIR+"K"+NORM+" - Konya's Room\n"+	
       ""+HIB+"J"+NORM+" - Justin's Room : "+HIK+"B"+NORM+" - Bone's Room : "+GRN+"C"+NORM+" - Cooper's Room : "+BOLD+BLK+"M"+NORM+" - Magus's Room\n\n";
     items = ({
       "wall","The wall is made of a black stone",
       "floor","The floor is made of a black stone",
       "stone","The stone is as black as the night sky",
});

dest_dir = ({
     "/players/jareel/areas/statue/enter.c","east",
     "/players/jareel/areas/statue/pkhall1.c","west",
});

}
