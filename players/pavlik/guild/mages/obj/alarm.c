#include "/players/pavlik/closed/colors.h"
string owner;

reset(arg){
 if(arg||root())
   return;
 owner = "Noone";
 call_out("rid_this", 1000);
}

id(str){
  return str == "alarm_obj" || str == "runes" ||
  str == owner+"'s alarm" || str == "markings"; 
}

short(){
  return;
}

long(){
  if(present("mageobj", this_player())) 
    write(capitalize(owner)+"'s alarm spell.\n");
  else
    write("Some strange markings on the ground.\n"+
    "You can't make any sense of them.\n");
  return;
}

drop(){ return 1; }
get(){ return; }

set_owner(str){ owner = str; }
query_owner(){ return owner; }

init(){
  if(!find_player(owner)){
    destruct(this_object());
    return 1;
  }
  if(this_player()->query_name()) {
  tell_object(find_player(owner),
  HIC+"<Alarm>"+NORM+": "+capitalize(this_player()->query_name())+
  " has entered the room.\n");
  }
}

