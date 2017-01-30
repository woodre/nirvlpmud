
reset(arg) {
     if(!arg)
       set_light(0);
}

init() {
     add_action("north","north");
     add_action("down","down");
}

north() {
     if(call_other("players/molasar/UNDER/tunnel18","query_passage") == 1) {
       write("There is a hole by the northern exit which blocks your passage.\n");
       return 1;
     } else
     call_other(this_player(),"move_player",
                    "north#players/molasar/UNDER/tunnel18");
     return 1;
}

down() {
     call_other(this_player(),"move_player",
                    "down#players/molasar/UNDER/tunnel20");
     return 1;
}

short() { return "A tunnel underneath the mountain"; }

long() {
     if(call_other("players/molasar/UNDER/tunnel18","query_passage") == 0) {
       write("A tunnel underneath the mountain.  A draft coming from a hole\n");
       write("in the floor sends a chill through you.\n");
       write("   There are two obvious exits:  north and down\n");
       return 1;
     } else
       write("A tunnel underneath the mountain.  A draft coming from a hole\n");
       write("in the floor send a chill through you.  A large hole in the \n");
       write("room to the north prevents passage in that direction.\n");
       write("   There is one obvious exit:  down\n");
}

