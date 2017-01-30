int time;

extra_look()
{
	if(environment() == this_player())
		write("Large stones have your feet pinned down!\n");
	else
		write(environment()->query_name() + " has "+possessive(environment())+" feet pinned down by large stones!\n");
}

id(str) { return str == "no_escape_bitch"; }
get() { return 1; }
drop() { return 1; }

init(){
  if( this_player() && this_player()->query_level() < 20 ) {
#ifndef __LDMUD__
      add_action("stun_move"); add_xverb("");
#else
      add_action("stun_move", "", 3);
#endif
  }
}

set_traplength(num) {
        time = num;
        call_out("end_trap", time);
}

stun_move(str) {
  if(environment(this_object())) {
    if(living(environment(this_object()))) {     
      if(str == "north" || str == "south" || str == "east" || str == "west" || str == "up" || str == "down" ||
         str == "in" || str == "out" || str == "northwest" || str == "southwest" || str == "northeast" ||
         str == "southeast" || str == "exit" || str == "leave") {
      write("You are still trapped in the earthen prison!\n");
      return 1;
      }
    }
  }
}

end_trap(){
        if(environment(this_object())){
                if(environment(environment(this_object())))
                tell_room(environment(environment(this_object())), capitalize(environment()->query_name())+" is no longer trapped!\n");
        else
                tell_room(environment(environment(this_object())), "You are no longer trapped!\n");
                destruct(this_object());
        }
}
