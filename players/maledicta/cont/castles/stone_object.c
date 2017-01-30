#include "/players/maledicta/ansi.h"

id(str){ return str == "stone" || str == "city_object"; }

short(){ return HIW+"The White Stone"+NORM; }

long(str){
write("This is a huge stone that stands nearly twenty feet in\n"+
      "height. It is of a pure white, unknown rock.  There is\n"+
      "not a scratch upon it.  You do notice a large black\n"+
      "hand print on the side.\n");
return 1;
}
        
get(){ return 0; } 
query_weight(){ return 100000; }
query_value(){ return 0; }

init(){
   add_action("enter","touch");
   }

enter(str){
  if(str != "hand" && str != "print" && str != "stone"){
     tell_object(this_player(), "Touch what?\n");
     return 1; 
     }
  if(!present("defender_guild", this_player())){
     tell_object(this_player(), "You touch the stone, but nothing happens.\n");
     return 1;
     }
  if(present("defender_guild", this_player())->query_stage() < 10){
     tell_object(this_player(), "You touch the stone, but nothing happens.\n");
     return 1;
     }
  tell_object(this_player(),
  HIY+"\n\n\n            YOU ARE PULLED INTO A SWIRLING VORTEX OF LIGHT\n\n\n"+NORM);
  this_player()->move_player("into a vortex of light#players/maledicta/closed/def/rooms/d1.c");
  return 1;
  }

