

#include "std.h"

reset(arg) {
    if(!arg)
     set_light(1);
}

short() { return "A winding trail"; }

long() {
     write("The trail begins to get very steep and difficult here.\n");
     write("There is a path through the rocks if you wish to go down.\n");
     write("   There are two obvious exits:  south and down\n");
}

init() {
     add_action("down","down");
     add_action("south","south");
}

down() {
     call_other(this_player(),"move_player",
         "down#players/molasar/UNDER/steep1");
     return 1;
}

south() {
     call_other(this_player(),"move_player",
         "south#players/molasar/UNDER/mount_top");
     return 1;
}
