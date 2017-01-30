#include <ansi.h>

id(str){ return str == "city" || str == "qualtor" || str == "qual'tor" || str == "city_object"; }

short(){ return "The city of "+BOLD+BLK+"Qual'tor"+NORM+"";; }


long(str){
write("The ruined outer wall of the city belies the new construction that\n"+
      "has taken place within. The City of Qual'tor has risen from the\n"+
      "ashes of severe warfare and is slowly being rebuilt.\n"+
      "You may <"+HIR+"enter"+NORM+"> the city at any time.\n");
return 1;
}
        
get(){ return 0; } 
query_weight(){ return 100000; }
query_value(){ return 0; }

init(){
   add_action("enter","enter");
   }

enter(str){
write("You make your way into the ancient City of Qual'tor.\n");
  this_player()->move_player("into the city#players/daranath/qualtor/hilltop.c");
  return 1;
  }

