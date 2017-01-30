
id(str) { return str == "doors" || str == "double doors" || str == "door"; }

int opened;

reset() {
     opened = 0;
}

query_opened() { return opened; }

short() { 
     if(opened == 0) 
       return "A double door";
     return "A double door (opened)";
}

long() {
     write("A set of large oak double doors.\n");
}

init() {
     add_action("open","open");
}

open(str) {
     if(!str) {
       write("Open what?\n");
       return 1;
     }
     if(str == "doors" || str == "double door" || str == "door") {
       write("You open the double door.\n");
       say(capitalize(this_player()->query_name())+" opens the door.\n");
       opened = 1;
       return 1;
     }
}

