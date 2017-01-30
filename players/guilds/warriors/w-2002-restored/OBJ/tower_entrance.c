#include "/players/maledicta/ansi.h"

id(str){ return str == "tower" || str == "warrior_tower"; }

reset(arg){ 
 if(arg) return;
 }

query_weight(){ return 1000000; }
query_value(){ return 0; }

init(){ 
  add_action("enter", "enter");
  }

short(){ return HIW+"Tower of the Warriors"+NORM; }

long(){ 
  write(
  "  This is the steel tower of the Warriors.  A school meant to teach\n"+
  "those seeking knowledge in the ways of the Warrior.  There is an open\n"+
  "door at its base that you can 'enter'.\n");
  return 1;
  }
 
enter(str){
  if(!str){ write("Enter what?\n"); return 1; }
  if(str == "door" || str == "tower"){
  this_player()->move_player("into the tower#players/maledicta/closed/w/rooms/sc1");
  return 1;
  }
  write("Enter what?\n");
  return 1;
  }
