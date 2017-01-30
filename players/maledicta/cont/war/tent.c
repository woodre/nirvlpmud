#include "/players/maledicta/ansi.h"

id(str){ return str == "tent" || str == "goblin_tent"; }

short(){ return YEL+"Goblin Command Tent"+NORM; }

long(){ 
    write(
"  This is a large fur covered tent. It is used by the\n"+
"goblin armies as a command center for their King and\n"+   
"his minions.  You may 'enter' at your own risk.\n"); 
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
  if(present("cont_goblin", environment(this_object()))){
    write("The goblin armies block you from entering the Tent!\n");
    return 1;
    }
  this_player()->move_player("into the Tent#players/maledicta/cont/war/inside_tent.c");
  return 1;
  }

