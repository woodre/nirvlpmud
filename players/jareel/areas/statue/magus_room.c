inherit "/players/jareel/room";
#include "/players/jareel/define.h"
#define ARENA "/players/jareel/areas/statue/arena/magus/rm1.c"

reset(arg) {
   
     if(!present("statue"))  {
       MOCO("/players/jareel/general_stuff/magus_statue.c"),this_object()); }
     
     if(arg) return;
     set_light(-2);
     short_desc=("Magus's personal "+RED+"Coffin"+NORM);
     long_desc=
       ""+BRED+BLK+"@@"+NORM+"|"+BRED+BLK+"@@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+GRN+"C"+NORM+"+"+NORM+BOLD+"X"+NORM+BLK+BRED+"@"+NORM+"\n"+ 
       ""+BRED+BLK+"@"+NORM+HIB+"J"+NORM+"+"+HIK+"B"+NORM+BLK+BRED+"@"+NORM+"     Magus's personal "+RED+"Hell"+NORM+" is currently in symbiosis.\n"+
       ""+BRED+BLK+"@"+NORM+HIB+"S"+NORM+"+"+NORM+HIR+"K"+NORM+BLK+BRED+"@"+NORM+"\n"+
       ""+NORM+"-"+NORM+"-+D"+BLK+BRED+"@"+NORM+" \n"+
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
    notify_fail("There is already someone in Magus's Arena.\n");
    return 0;
  }

  write("You start the arena.\n");
  say((string)this_player()->query_name()+" heads off to fight Magus.\n");
  move_object(this_player(), "/players/jareel/areas/statue/arena/magus/rm1.c");
  command("glance", this_player());
  return 1;
}



