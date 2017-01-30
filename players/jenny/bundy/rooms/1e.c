inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
     set_listen(""+BOLD+"You hear the buzzing of traffic."+NORM+"\n");
     set_smell(""+BOLD+"You gag at the smell of exhaust fumes."+NORM+"\n");
short_desc=("A mean Chicago street.");
long_desc=
"You are on a busy street in Chicago.  Cars are driving\n"+
"recklessly all around you.  This is Chicago traffic\n"+
"at it's worst.  There is a sign on the side of the\n"+
"street.\n";
items = ({
"cars","All of these cars are nicer than Al Bundy's dodge",
"street","A busy, pothole infested Chicago street",
"sign","The sign reads:  "+RED+"PK area"+NORM+"\n",
});
dest_dir = ({
"/players/jenny/bundy/rooms/2e","east",
 "/players/jenny/areaentrance","leave",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
