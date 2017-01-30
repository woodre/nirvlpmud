/* Dars base code 'Thanks Dar' */
#define tp this_player()->query_name()
#include "/players/jareel/define.h"
inherit "room/room";

reset(arg){
  
     if(!present("sign"))  {
       MOCO("/players/jareel/general_stuff/deplist.c"),this_object());
}

     if(arg) return;
     set_light(1);
     short_desc = (BOLD+"Legendary Depository"+NORM);
     long_desc =
       ""+BRED+BLK+"@@"+NORM+"|"+BRED+BLK+"@@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+GRN+"C"+NORM+"+"+BOLD+BLK+"M"+NORM+BLK+BRED+"@"+NORM+"     This is the Hall of Legends Depository.  This room is rather \n"+ 
       ""+BRED+BLK+"@"+NORM+HIB+"J"+NORM+"+"+HIK+"B"+NORM+BLK+BRED+"@"+NORM+"     small with a small machine on the eastern wall.  The walls \n"+
       ""+BRED+BLK+"@"+NORM+HIB+"S"+NORM+"+"+HIR+"K"+NORM+BLK+BRED+"@"+NORM+"     and floor seem to be made of a dark onyx flag stone.  To the \n"+
       ""+NORM+"-"+NORM+"-+"+NORM+BOLD+"X"+NORM+BLK+BRED+"@"+NORM+"     west of this room is the way out.\n"+
       ""+BRED+BLK+"@@"+NORM+"E"+BLK+BRED+"@@"+NORM+"     \n"+     
       "\n"+
       "E - Entrance/Exit : D - Depository  : "+HIB+"S"+NORM+" - Stone's Room  : "+HIR+"K"+NORM+" - Konya's Room\n"+	
       ""+HIB+"J"+NORM+" - Justin's Room : "+HIK+"B"+NORM+" - Bone's Room : "+GRN+"C"+NORM+" - Cooper's Room : "+BOLD+BLK+"M"+NORM+" - Magus's Room\n\n";
     items = ({
       "stone","The stone is as black as the night sky",
       "machine","There is a sign by the machine you should 'read'",
       "wall","The wall is made of a black stone",
       "floor","The floor is made of a black stone",
});

dest_dir = ({
     "/players/jareel/areas/statue/enter.c","west",
});
}
 
init() {
     ::init();
       if(!present("depositor",this_object())) 
       move_object(clone_object("/players/jareel/general_stuff/depositor.c"), this_object());
     add_action("search","search");
}

search() {
     write("Sorry, noone has dropped any coins recently.\n");
     say(tp +" searches the area.\n");
return 1;
}
