int time;

id(str) { return str == "stun"; }
get() { return 1; }
drop() { return 1; }

init(){

#ifndef __LDMUD__
      add_action("stun_move"); add_xverb("");
#else
      add_action("stun_move", "");
#endif
}

set_saplength(num) {
	time = num;
	call_out("end_sap", time);
}

stun_move(str) {
  if(environment(this_object())) {
    if(living(environment(this_object()))) {     
      if(str == "north" || str == "south" || str == "east" ||
         str == "west" || str == "up" || str == "down" ||
         str == "in" || str == "out" || str == "northwest" ||
         str == "southwest" || str == "northeast" ||
         str == "southeast" || str == "exit" || str == "leave") {
      write("You're sapped and cannot move!\n");
      return 1;
      }
    }
  }
}

end_sap(){
	if(environment(this_object())){
		if(environment(environment(this_object())))
		tell_room(environment(environment(this_object())), capitalize(environment()->query_name())+" is no longer sapped!\n");
	else
		tell_room(environment(environment(this_object())), "You are no longer sapped!\n");
		destruct(this_object());
	}
}
			
