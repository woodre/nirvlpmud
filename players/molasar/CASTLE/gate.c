


int state;

query_state() { return state; }

reset(arg) {
    if(!arg)
      return;
      state = 0;
}

id(str) { return str == "gate"; }

short() {
    if(state == 1) {
       return "A heavy iron gate (open)";
    } else
      return "A heavy iron gate (closed)";
}

long() {
     write("This is a large iron gate.\n");
}

init() {
     add_action("open","open");
     add_action("close","close");
}

open(str) {
     string me;
     me = this_player()->query_name();

     if(!str) {
       write("Open what?\n");
       return 1;
     }
     if(str == "gate") {
       if(state == 1) {
         write("The gate is already open.\n");
         return 1;
       }
       write("You open the gate.\n");
       say(capitalize(me)+" opens the gate.\n");
       state = 1;
       return 1;
     }
}

close(str) {
     string me;
     me = this_player()->query_name();

     if(!str) {
       write("Close what?\n");
       return 1;
     }
     if(str == "gate") {
       if(state == 0) {
         write("The gate is already closed.\n");
         return 1;
       } else
       write("You close the gate.\n");
       say(capitalize(me)+" closes the gate.\n");
       state = 0;
       return 1;
     }
}

