inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
short_desc=("Parking lot.");
long_desc=
"This is the parking lot for the Jiggly Room.  There is a\n"+
"busy intersection to the north.  Cars are parked all around\n"+
"you, it is hard to find a parking space.  It must be 'D-cup\n"+
"night inside.\n";
items = ({
"cars","All of these cars are nicer than Al Bundy's dodge",
"intersection","A busy intersection",
});
dest_dir = ({
"/players/jenny/bundy/rooms/3e","north",
 "/players/jenny/bundy/rooms/3g","enter",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
