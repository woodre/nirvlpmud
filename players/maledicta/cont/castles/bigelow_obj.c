#include "/players/maledicta/ansi.h"

id(str){ return str == "town" || str == "bigelow" || str == "city_object"; }

short(){ return "The Town of Bigelow"; }


long(str){
write("  Before you is a path leading north to the small\n"+
      "town of Bigelow.  You may enter at any time.\n");
return 1;
}
        
get(){ return 0; } 
query_weight(){ return 100000; }
query_value(){ return 0; }

init(){
   add_action("enter","enter");
   }

enter(str){
  this_player()->move_player("into bigelow#players/pain/NEW/road1.c");
  return 1;
  }

