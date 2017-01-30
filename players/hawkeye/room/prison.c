short() {
    return "Hawkeye's Prison";
}

long() {
    write("You are in Hawkeye's Prison.\n");
       write("Obviously there is something you have to done to be here.\n");
    write("There are no exits.\n");
}

reset(arg) {
    if (arg)
	return;
    set_light(1);
}

init() {
#ifndef __LDMUD__
         add_action("quit"); add_xverb(" ")
#else
           add_action("quit"," ",3);
#endif
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
