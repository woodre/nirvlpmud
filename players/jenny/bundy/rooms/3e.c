inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
     set_listen(""+BOLD+"You hear the buzzing of traffic."+NORM+"\n");
     set_smell(""+BOLD+"You gag at the smell of exhaust fumes."+NORM+"\n");
short_desc=("An intersection.");
long_desc=
"You are at an intersection of two streets in Chicago.\n"+      
"Cars are driving recklessly all around you.  This is Chicago\n"+
"traffic at its worst.  It's rumored that the Bundy family\n"+
"lives to the north of here.  To the south, you can clearly\n"+
"see the neon sign of The Jiggly Room.\n";

items = ({
"sign",""+HIM+"THE JIGGLY ROOM"+NORM+"\n",
"cars","All of these cars are nicer than Al Bundy's dodge",
"street","A busy, pothole infested Chicago street",
});

dest_dir = ({
"/players/jenny/bundy/rooms/3d","north",
 "/players/jenny/bundy/rooms/3f","south",
"/players/jenny/bundy/rooms/2e","west",
 "/players/jenny/bundy/rooms/4e","east",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
