inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
set_listen(""+BOLD+"You can hear heavy metal music playing in a room ahead."+NORM+"\n");
short_desc=(""+CYN+"The Bundy's upstairs hallway"+NORM+"");
long_desc=
"This is the upstairs hallway of the Bundy's house.  It leads\n"+
"to the bedrooms.  Al has been known to run down these\n"+
"hallways screaming while trying to get away from Peg on\n"+
"sex night.\n";
dest_dir = ({
 "/players/jenny/bundy/rooms/u2b","east",
 "/players/jenny/bundy/rooms/hb3","downstairs",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
