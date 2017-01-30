#include "/players/maledicta/ansi.h"

id(str){ return str == "village" || str == "city_object"; }

short(){ return "The village of "+HIG+"Terk'ula"+NORM+"";; }


long(str){
write("You stand before the Lizardman village of\n"+
      "Terk'ula.  It is a small town that is\n"+
      "surrounded by a wooden wall. You may enter\n"+
      "it anytime and feel mostly safe.\n");
return 1;
}
        
get(){ return 0; } 
query_weight(){ return 100000; }
query_value(){ return 0; }

init(){
   add_action("enter","enter");
   }

enter(str){
  this_player()->move_player("into the village#players/maledicta/cont/ltown/rooms/l1.c");
  return 1;
  }

