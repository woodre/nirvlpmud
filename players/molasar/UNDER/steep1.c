


#include "std.h"

reset(arg) {
    if(!arg)
      set_light(1);
}

short() { return "A steep path down the mountain"; }

long() { 
     write("The path is alot steeper than it looked.  You can barely see\n");
     write("due to all the dust and rocks you are kicking up because of\n");
     write("your frequent slips.\n");
     write("   There are two obvious exits:  up and down\n");
}
init() {
    add_action("up","up");
    add_action("down","down");
}

up() {
    call_other(this_player(),"move_player",
        "up#players/molasar/UNDER/trail1");
    return 1;
}

down() {
    call_other(this_player(),"move_player",
        "down#players/molasar/UNDER/shelf");
    return 1;
}

