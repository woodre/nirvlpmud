inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
     set_listen(""+BOLD+"You hear the buzzing of traffic."+NORM+"\n");
     set_smell(""+BOLD+"You gag at the smell of exhaust fumes."+NORM+"\n");
     set_search(""+BOLD+"You find a bunch of litter on the ground."+NORM+"\n");
short_desc=("A mean Chicago street.");
long_desc=
"You are on a busy street in Chicago.  Cars are driving\n"+     
"recklessly all around you.  This is Chicago traffic\n"+
"at it's worst.  You can see a traffic light in front of\n"+
"you.  The Neon sign to the east is impossible to ignore.\n";
items = ({
"light","This is a traffic light, and it is "+HIG+"GREEN."+NORM+"\n",
"cars","All of these cars are nicer than Al Bundy's dodge",
"street","A busy, pothole infested Chicago street",
"sign",""+HIM+"THE JIGGLY ROOM"+NORM+"\n",
"litter","Discarded fast food packaging and soda cans scattered along the side of the street",
});

dest_dir = ({
"/players/jenny/bundy/rooms/1e","west",
 "/players/jenny/bundy/rooms/3e","east",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
