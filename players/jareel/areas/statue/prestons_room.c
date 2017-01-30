inherit "/players/jareel/room";
#include "/players/jareel/define.h"
#define ARENA "/players/jareel/areas/statue/arena/preston/rm1.c"

reset(arg) {

     if(arg) return;
     set_light(1);
     short_desc=(HIK+"Preston's Whirlwind"+NORM);
     long_desc=
       ""+BRED+BLK+"@@"+NORM+"|"+BRED+BLK+"@@"+NORM+"\n"+
       ""+BRED+BLK+"@"+RED+"E"+NORM+"+"+BRED+BLK+"@@"+NORM+"\n"+ 
       ""+BRED+BLK+"@"+NORM+GRN+"H"+NORM+"+"+HIK+"B"+NORM+BRED+BLK+"@"+NORM+"     Sand blurs your vision!!!!"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+BOLD+"X"+NORM+"+"+RED+"H"+NORM+BRED+BLK+"@"+NORM+"          \n"+
       ""+BLK+BRED+"@"+NORM+HIY+"T"+NORM+"+"+HIB+"S"+NORM+BRED+BLK+"@"+NORM+"\n"+
       ""+BRED+BLK+"@"+NORM+HIY+"B"+NORM+"+"+HIK+"H"+NORM+BRED+BLK+"@"+NORM+"     \n"+     
       "\n"+
       ""+HIY+"B"+NORM+" - Breeti's Room : "+HIK+"H"+NORM+" - Hardly's Room : "+HIY+"T"+NORM+" - Tweak's Room : "+HIB+"S"+NORM+" - Sparkle's Room\n"+	
       ""+RED+"P"+NORM+" - Preston's Room : "+RED+"H"+NORM+" - Humble's Room  :"+GRN+"H"+NORM+" - Hoyle's Room : "+RED+"B"+NORM+" - Bleh's Room\n"+
""+RED+"R"+NORM+" - Entreri's Room\n";

       ""+HIY+"B"+NORM+" - Breeti's Room : "+HIK+"H"+NORM+" - Hardly's Room : "+HIY+"T"+NORM+" - Tweak's Room : "+HIB+"S"+NORM+" - Sparkle's Room\n"+	
       ""+RED+"P"+NORM+" - Preston's Room : "+RED+"H"+NORM+" - Humble's Room\n";
     items = ({
       "","",
       "","",
});
 

dest_dir = ({
     
      "/players/jareel/areas/statue/hall7.c","east",
     
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
    notify_fail("There is already someone in Preston's Arena.\n");
    return 0;
  }

  write("You start the arena.\n");
  say((string)this_player()->query_name()+" heads off to fight Preston.\n");
  move_object(this_player(), "/players/jareel/areas/statue/arena/preston/rm1.c");
  command("glance", this_player());
  return 1;
}



