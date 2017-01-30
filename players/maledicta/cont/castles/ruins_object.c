#include "/players/maledicta/ansi.h"

id(str){ return str == "ruins" || str == "city_object"; }

short(){ return HIW+"The Ruins"+NORM; }


long(str){
write("Before you stands the ruined remains of a once great\n"+
      "temple.  Dark clouds seem to hang over the area. You\n"+
      "may enter at your own risk.\n");
return 1;
}
        
get(){ return 0; } 
query_weight(){ return 100000; }
query_value(){ return 0; }

init(){
   add_action("enter","enter");
   }

enter(str){
  this_player()->move_player("into the ruins#players/maledicta/ruins/rooms/r1.c");
  return 1;
  }

