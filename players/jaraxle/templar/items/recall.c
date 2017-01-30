
#include "/players/jaraxle/define.h"
id(str){ return str == "scroll" || str == "recall" || str == "recall_scroll"; }

init() {
add_action("accept","invoke");
}

query_weight(){ return 0; }
query_value(){ return 0; }

short(){ return "A scroll of "+HIY+"Recall"+NORM+""; }
long(){
    write("A rolled up scroll with a "+HIY+"yellow ribbon"+NORM+" tied around it.\nAll you need to do is "+HIY+"<"+HIW+"invoke"+HIY+">"+NORM+" it.\n");
	return 1;}

accept(str){
	if(!str){
		write("Invoke what?\n");
		return 1;
	}
  if(str != "scroll"){
      write("Invoke what?\n");
      return 1;
}
  write("You read the scroll out loud.\n");
  if(call_other(environment(this_player()), "realm", 0 == "NT")) {
    write("You cannot teleport from here. The scroll crumbles.\n");
    destruct(this_object());
    return 1;
   }
  tell_room(environment(this_player()), this_player()->query_name() + 
  " vanishes in a bright "+HIY+"flash"+NORM+" of "+HIW+"light"+NORM+".\n");
move_object(this_player(), "/players/jaraxle/templar/rooms/library.c");
command("look",TP);
  tell_room(environment(this_player()), this_player()->query_name() + " arrives in a "+HIY+"flash"+NORM+" of "+HIW+"light"+NORM+".\n");
  destruct(this_object());
  return 1;
}
drop(){
  write("The scroll vanishes as it reaches the ground.\n");
  destruct(this_object());
  return 1;
}
