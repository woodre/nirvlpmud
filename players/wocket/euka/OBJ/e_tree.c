#include "/players/wocket/closed/ansi.h"
#include "../Def.h"
string dir;

id(str){ return (str == "tree" || str == "euka" || str == "euka tree"); }
short(){ return GRN+"A giant Euka tree"+OFF; }

long(){
  write("A large Euka tree that seems to stretch to the clouds with\n"+
  "branches that spread like spider webbing across the sky.  You\n"+
  "may want to 'climb' up the tree.\n");
}

get(){ return 0; }
init(){
  add_action("climb_tree","climb");
}

climb_tree(str){
  if(!str){
    notify_fail("What would you like to climb?\n");
    return 0;
  }
  if((str != "tree" && str != "euka" && str != "euka tree")){
    notify_fail("That is not here to climb.\n");
    return 0;
  }
  write("You quickly climb the tree.\n");
  say(TPN+" quickly climbs the Euka tree.\n");
  move_object(TP,dir);
  say(TPN+" arrives.\n");
  command("glance",TP);
  return 1;
}

set_dir(a){ dir = a; }
query_dir(){ return dir; }
