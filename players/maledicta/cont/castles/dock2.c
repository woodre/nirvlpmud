#include "/players/maledicta/ansi.h"

id(str){ return str == "dock" || str == "dock_object"; }

short(){ return HIW+"a dock"+NORM; }


long(str){
write("This is a small dock with many boats stationed along its\n"+
      "length.  You may 'sail' back to the mainland of Nirvana\n"+
      "at any time.\n");
return 1;
}
        
get(){ return 0; } 
query_weight(){ return 100000; }
query_value(){ return 0; }

init(){
   add_action("enter","sail");
   }

enter(str){
  write("You climb aboard a boat and sail to Nirvana.\n");
/*
  this_player()->move_player("onto a boat#players/reflex/realms/coastline/plains7.c");
*/
  this_player()->move_player("onto a boat#players/wren/Area/coastline/coast2.c");
  return 1;
  }

