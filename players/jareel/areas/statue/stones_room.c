inherit "/players/jareel/room";
#include "/players/jareel/define.h"
#define ARENA "/players/jareel/areas/statue/arena/stone/rm1.c"

reset(arg) {

     if(!present("statue"))  {
       MOCO("/players/jareel/general_stuff/stone_statue.c"),this_object()); }
     if(arg) return;
     set_light(1);
     short_desc=("Stone's Forge");
     long_desc=
       ""+BRED+BLK+"@@"+NORM+"|"+BRED+BLK+"@@"+NORM+"     You have entered a large circular room crafted from immaculate\n"+
       ""+BRED+BLK+"@"+NORM+GRN+"C"+NORM+"+"+BOLD+BLK+"M"+NORM+BLK+BRED+"@"+NORM+"     white marble.  In the center of the room lies a massive forge,\n"+ 
       ""+BRED+BLK+"@"+NORM+HIB+"J"+NORM+"+"+HIK+"B"+NORM+BLK+BRED+"@"+NORM+"     its intense fires, sustained by faith and determination alone,\n"+
       ""+BRED+BLK+"@"+NORM+BOLD+"X"+NORM+"+"+NORM+HIR+"K"+NORM+BLK+BRED+"@"+NORM+"     burn without fuel.  An anvil forged from pure adamantine rests\n"+
       ""+NORM+"-"+NORM+"-+D"+BLK+BRED+"@"+NORM+"     unharmed in the fire's center.  Various racks of weapons and \n"+
       ""+BRED+BLK+"@@"+NORM+"E"+BLK+BRED+"@@"+NORM+"     armors in differing stages of completion line the wall.\n"+     
       "\n"+
       "E - Entrance/Exit : D - Depository  : "+HIB+"S"+NORM+" - Stone's Room  : "+HIR+"K"+NORM+" - Konya's Room\n"+	
       ""+HIB+"J"+NORM+" - Justin's Room : "+HIK+"B"+NORM+" - Bone's Room : "+GRN+"C"+NORM+" - Cooper's Room : "+BOLD+BLK+"M"+NORM+" - Magus's Room\n\n";
     items = ({
       "plaque","Stone's Room",
       "wall","The room is empty except a small plaque",
});
 


dest_dir = ({
     "/players/jareel/areas/statue/hall1.c","east",
});

}
  
     int peeps;void init() {
       ::init();
       if(!this_player())
     return;
       add_action("Search","search");
       add_action("Start","start");
     peeps++;
       if(find_call_out("heat") == -1)
     call_out("heat", random(10) + 3);
       }void exit() {  peeps--;
       if(peeps <= 0)    while(remove_call_out("wind") != -1) ;
       }void heat() {  object ob,next;
     string msg;
       switch(random(2)) {    case 0: msg= "The heat of the forge washes over you.\n";
     break;
     case 1: msg= "The heat of the forge washes over you.\n";
     break;
     }  tell_room(this_object(),msg);
     while(remove_call_out("wind") != -1);
     call_out("heat", random(10) + 3);
  }

     Search(str) {
     if(!str) { write("Search what?\n"); return 1; }
       write("You search the "+str+" but find nothing special.\n");
       say(this_player()->query_name()+" searches around for something.\n");
     return 1;
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
    notify_fail("There is already someone in Stone's Arena.\n");
    return 0;
  }

  write("You start the arena.\n");
  say((string)this_player()->query_name()+" heads off to fight Stone.\n");
  move_object(this_player(), "/players/jareel/areas/statue/arena/stone/rm1.c");
  command("glance", this_player());
  return 1;
}


