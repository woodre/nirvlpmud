inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
set_listen(""+BOLD+"You can hear heavy metal music in the room to the south."+NORM+"\n");
short_desc=(""+CYN+"The Bundy's upstairs hallway"+NORM+"");
long_desc=
"This is the upstairs hallway of the Bundy's house.  It leads\n"+
"to the bedrooms.  Bud's room is to the north, Kelly's room\n"+
"is to the south, and Al and Peg's room is further to the east.\n"+
"Al has been known to run past here while hiding from Peg\n"+
"on sex night.\n";
dest_dir = ({
 "/players/jenny/bundy/rooms/u2a","north",
 "/players/jenny/bundy/rooms/u2c","south",
 "/players/jenny/bundy/rooms/u1b","west",
 "/players/jenny/bundy/rooms/u3b","east",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
