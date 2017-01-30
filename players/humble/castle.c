#define DEST "room/south/sforst13"
#include "/players/humble/ansi.h"

    id(str) { return  str == "bucket"; }
short() {
   return HIR+"A large bucket of Sand"+NORM;
}

long() {
    write("This is a large bucket of Sand with a short ladder on the side of it.\n"+
    "perhaps one might climb the ladder and enter the bucket of sand.\n");
}


init() {
    add_action("climb","climb");
}

    climb(str) {
    if(!str){ write("What would you like to climb?\n");
    return 1; }
    if(str == "ladder"){
    write("You climb the ladder and fall into a giant bucket of sand.\n");
    write("Humble grants you passage into his realm.\n");
    move_object(this_player(), "/players/humble/area1/rooms/entrance.c");
    command("look", this_player());
    return 1; }
}

reset(arg) {
    if (arg)
    return;
    move_object(this_object(), DEST);
}
is_castle(){return 1;}
