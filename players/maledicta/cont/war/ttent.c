#include "/players/maledicta/ansi.h"

id(str){ return str == "tent" || str == "templar_tent"; }

short(){ return HIG+"Templar "+HIW+"Command Tent"+NORM; }

long(){ 
    write(
"  You stand before the command tent of the Templar Knights.\n"+
"It is designed in a rich green cloth with gold trim around\n"+
"the front flap. It looks sturdy.\n"+
"You can 'enter' if you have permission.\n"); 
    return 1;
    }
        
get(){ return 0; } 
query_weight(){ return 100000; }
query_value(){ return 0; }

init(){
   add_action("enter","enter");
   }

enter(str){
  if(!str){ write("enter what?\n"); return 1; }
  if(!present("KnightInvite", this_player())){
    write("You are not allowed!\n");
    return 1;
    }
  this_player()->move_player("into the Tent#players/maledicta/cont/war/inside_tent2.c");
  return 1;
  }

