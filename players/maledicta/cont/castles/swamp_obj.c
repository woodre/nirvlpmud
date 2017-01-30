#include "/players/maledicta/ansi.h"

id(str){ return str == "swamp" || str == "city_object"; }

short(){ return GRN+"a "+HIG+"Swamp"+NORM; }


long(str){
write("This is a large swampy area.  You may enter at\n"+
      "your own risk.\n");
return 1;
}
        
get(){ return 0; } 
query_weight(){ return 100000; }
query_value(){ return 0; }

init(){
   add_action("enter","enter");
   }

enter(str){
  this_player()->move_player("into the swamp#players/dusan/area1/rooms/swamp1.c");
  return 1;
  }

