inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("kelly bundy"))  {
MOCO("/players/jenny/bundy/mobs/kelly.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_listen(""+BOLD+"Your ears nearly bleed at the sound of Anthrax blasting on the stereo."+NORM+"\n");
short_desc=(""+CYN+"Kelly Bundy's room."+NORM+"");
long_desc=
"This room belongs to Kelly Bundy.  She often goes into her room\n"+
"to get away from her creepy brother, or to entertain her male\n"+
"friends.  There is a bed next to the window, and posters on the\n"+
"wall.\n";
items = ({
"wall","A wall, with posters on it",
"bed","The box-springs look worn out",
"posters","Posters of various heavy metal groups",
"window","Kelly is thankful this window doesn't face the Darcy's house",
});

dest_dir = ({
 "/players/jenny/bundy/rooms/u2b","north",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
