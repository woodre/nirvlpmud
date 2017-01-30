inherit "/players/jareel/room";
#include "/players/jareel/define.h"
#define ARENA "/players/jareel/areas/statue/arena/konya/rm1.c"

reset(arg) {
     
     if(arg) return;

     if(!present("statue"))  {
       MOCO("/players/jareel/general_stuff/konya_statue.c"),this_object()); }

     set_light(1);
     short_desc=("Konya's Cybernetic Machine Shop");
     long_desc=
       ""+BRED+BLK+"@@"+NORM+"|"+BRED+BLK+"@@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+GRN+"C"+NORM+"+"+BOLD+BLK+"M"+NORM+BLK+BRED+"@"+NORM+"\n"+ 
       ""+BRED+BLK+"@"+NORM+HIB+"J"+NORM+"+"+HIK+"B"+NORM+BLK+BRED+"@"+NORM+"     Konya's Cybernetic Machine Shop is in need of spare parts.\n"+
       ""+BRED+BLK+"@"+NORM+HIB+"S"+NORM+"+"+NORM+BOLD+"X"+NORM+BLK+BRED+"@"+NORM+"\n"+
       ""+NORM+"-"+NORM+"-+D"+BLK+BRED+"@"+NORM+" \n"+
       ""+BRED+BLK+"@@"+NORM+"E"+BLK+BRED+"@@"+NORM+"\n"+     
       "\n"+
       "E - Entrance/Exit : D - Depository  : "+HIB+"S"+NORM+" - Stone's Room  : "+HIR+"K"+NORM+" - Konya's Room\n"+	
       ""+HIB+"J"+NORM+" - Justin's Room : "+HIK+"B"+NORM+" - Bone's Room : "+GRN+"C"+NORM+" - Cooper's Room : "+BOLD+BLK+"M"+NORM+" - Magus's Room\n\n";
     items = ({
       "plaque","Konya's Room",
       "wall","The room is empy cept a small plaque",
});



dest_dir = ({
     "/players/jareel/areas/statue/hall1.c","west",
});

}

     init() {
       ::init();
         add_action("Start","start");
     }


  Start(string str){
     if(!str || str != "arena"){
       notify_fail("What do you want to do?\n");
     return 0;
   }
   if(this_player()->query_level() < 19){
     write("Not until you are level 19.\n");
   return 1;
 
   }

  if ((status)ARENA->cannot_enter())
  {
    notify_fail("There is already someone in Konya's Arena.\n");
    return 0;
  }

  write("You start the arena.\n");
  say((string)this_player()->query_name()+" heads off to fight Konya.\n");
  move_object(this_player(), "/players/jareel/areas/statue/arena/konya/rm1.c");
  command("glance", this_player());
  return 1;
}



