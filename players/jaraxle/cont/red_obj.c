#include "/players/maledicta/ansi.h"

id(str){ return str == "cave" || str == "city_object"; }

short(){ return HIW+"The Cave of the "+HIR+"Red Dragon"+HIW+" Clan"+NORM; }


long(str){
write("Before you stands a huge cave that leads deep into the\n"+
      "mountain.  Before it lies the bones of fallen animals\n"+
      "and warriors, strewn about two feet deep.  You may enter\n"+
      "the cave, but you have a bad feeling about it.\n");
return 1;
}
        
get(){ return 0; } 
query_weight(){ return 100000; }
query_value(){ return 0; }

init(){
   add_action("enter","enter");
   }

enter(str){
  this_player()->move_player("into the cave#players/maledicta/cont/rdragon/rooms/r1.c");
  return 1;
  }

