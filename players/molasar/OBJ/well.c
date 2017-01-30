
id(str) { return str == "well"; }

short() { return "A large stone well"; }

long() {
     write("An ancient well which was once a source of water for the castle.\n");
     write("It is too dark to see very far down the well, but you notice metal\n");
     write("rungs going down one side that you can climb down.\n");
}

init() {
     add_action("down","down");
}

down() {
     call_other(this_player(),"move_player",
                    "down#players/molasar/CASTLE/wellrm1");
     return 1;
}

