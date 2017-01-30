inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("exotic dancer"))  {
MOCO("/players/jenny/bundy/mobs/dancer.c"),this_object()); }
    if(arg) return;
    set_light(1);
     set_smell(""+YEL+"It smells like stale beer."+NORM+"\n");
     set_search(""+BOLD+"You notice spilled beer and peanuts on the floor."+NORM+"\n");
     set_listen(""+RED+"You hear upbeat music."+NORM+"\n");
short_desc=(""+MAG+"The Jiggly Room"+NORM+"");
long_desc=
"These are decent seats.  From this table, you can see the\n"+
"girls very well, and they often come over to offer lap\n"+
"dances.  This is much better than being home with the\n"+
"wife and kids, huh?\n";
items = ({
"table","Someone spilled bear on this table",
"girls","Looking at these sexy girls, you are reminded of the Bundy credo.  'Hooters hooters\n"+
"yum, yum, yum.  Hooters hooters on a girl that's dumb'",
});

dest_dir = ({
"/players/jenny/bundy/rooms/3h","west",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
