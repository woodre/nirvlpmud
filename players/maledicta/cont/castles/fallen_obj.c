#include "/players/maledicta/ansi.h"

id(str){ return str == "lands" || str == "city_object" ||
                str == "fallen lands"; }

short(){ return HIW+"The Fallen Lands"+NORM; }


long(str){
write("Before you is a deep forest known as the Fallen Lands.\n"+
      "You may enter it at any time.\n");
return 1;
}
        
get(){ return 0; } 
query_weight(){ return 100000; }
query_value(){ return 0; }

init(){
   add_action("enter","enter");
   }

enter(str){
  this_player()->move_player("into the forest#players/zeus/realm/city/ent.c");
  return 1;
  }

