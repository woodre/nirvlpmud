#include "/players/maledicta/ansi.h"

id(str){ return str == "cave" || str == "city_object"; }

short(){ return HIW+"a cave"+NORM; }


long(str){
write("A small cave stands before you.  The interior appears\n"+
      "very dark from out here.  You may enter it if you dare.\n");
return 1;
}
        
get(){ return 0; } 
query_weight(){ return 100000; }
query_value(){ return 0; }

init(){
   add_action("enter","enter");
   }

enter(str){
  this_player()->move_player("into the cave#players/maledicta/cave/rooms/entrance.c");
  return 1;
  }

