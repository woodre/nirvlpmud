
id(str) { return str == "scroll"; }

init() {
add_action("accept","invoke");
}

query_weight(){ return 0; }
query_value(){ return 0; }

short(){return "A scroll of return"; }
long(){
	write("A rolled up scroll. All you need do is 'invoke' it.\n");
	return 1;}

accept(str){
this_player()->add_hit_point(-200);
	if(!str){
		write("invoke what?\n");
		return 1;
	}
  if(str != "scroll"){
      write("Invoke what?\n");
      return 1;
}
  write("You read the scroll outloud.\n");
  if(call_other(environment(this_player()), "realm", 0 == "NT")) {
    write("You cannot teleport from here. The scroll vanishes.\n");
    destruct(this_object());
    return 1;
   }
  tell_room(environment(this_player()), this_player()->query_name() + 
  " vanishes in a bright flash of light.\n");
  move_object(this_player(), "/players/jaraxle/templar/rooms/mage_room");
  tell_room(environment(this_player()), this_player()->query_name() + " arrives in a flash of light.\n");
  destruct(this_object());
  return 1;
}
drop(){
  write("The scroll vanishes as it reaches the ground.\n");
  destruct(this_object());
  return 1;
}
