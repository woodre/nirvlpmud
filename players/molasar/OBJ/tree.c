
id(str) { return str == "tree" || str == "oak tree"; }

reset(arg) {
     if(!arg)
       return;
}

init() {
     add_action("climb","climb");
}

climb(str) {
     if(!str) {
       write("Climb what?\n");
       return 1;
     }
     if(str == "tree" || str == "oak tree") {
       call_other(this_player(), "move_player",
                      "up the tree#players/molasar/CASTLE/tree_room");
       return 1;
     }
}

short() { return "A majestic oak tree"; }

long() {
     write("This is a full grown oak tree.  It looks like it'd be fun to climb.\n");
}


