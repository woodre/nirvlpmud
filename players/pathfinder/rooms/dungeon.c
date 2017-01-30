short() {
      return "Pathfinder's Jail Cell";
}

long() {
   write("You must have done something to end up here.\n");
   write("You are stuck in Pathfinder's prison.\n");
   write("\nThere are NO exits.\n");
}

reset(arg) {
    if (arg)
	return;
    set_light(1);
}

init() {
    add_action("quit"); add_xverb("");
       add_action("nope");
}

quit(){
    if (call_other(this_player(),"query_level", 0) < 21)
      {
          long();
          write("You can't do that here.\n");
       return 1;
       }
    return 0;
   }
