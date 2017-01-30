inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("exotic dancer"))  {
MOCO("/players/jenny/bundy/mobs/dancer.c"),this_object()); 
MOCO("/players/jenny/bundy/mobs/dancer.c"),this_object()); 
MOCO("/players/jenny/bundy/mobs/dancer.c"),this_object()); }
    if(arg) return;
    set_light(1);
     set_listen(""+RED+"You hear upbeat music."+NORM+"\n");
short_desc=(""+MAG+"The Jiggly Room Stage"+NORM+"");
long_desc=
"This is the stage where the girls dance to entertain the\n"+
"drunken men.  The stage is polished hardwood, and there\n"+
"are three poles for the girls to use during their dances.\n";

items = ({
"poles","Just metal poles stretching from the ceiling to the stage",
"stage","A polished hardwood stage for the girls to strut their stuff on",
});

dest_dir = ({
"/players/jenny/bundy/rooms/3h","off",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
