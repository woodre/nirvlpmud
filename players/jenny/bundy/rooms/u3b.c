inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
short_desc=(""+CYN+"The Bundy's upstairs hallway"+NORM+"");
long_desc=
"This is the upstairs hallway of the Bundy's house.  It leads\n"+
"to the bedrooms.  Al and Peg's room is to the east.  Bud and\n"+
"Kelly's rooms are west of here.  Al has been known to run\n"+
"down this hall while hiding from Peg on sex night.\n";
dest_dir = ({
 "/players/jenny/bundy/rooms/u2b","west",
 "/players/jenny/bundy/rooms/u4b","east",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
