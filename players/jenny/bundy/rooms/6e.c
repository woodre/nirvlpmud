inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
     set_listen(""+BOLD+"You hear the buzzing of traffic."+NORM+"\n");
     set_smell(""+BOLD+"You gag at the smell of exhaust fumes."+NORM+"\n");
short_desc=("A mean Chicago street.");
long_desc=
"You are on a busy street in Chicago.  Traffic is very\n"+
"heavy here.  You can see the mall to the east.  Cars are\n"+
"driving recklessly all around you.  This is Chicago\n"+
"traffic at its worst.\n";
items = ({
"mall","This is the mall where Al Bundy works.  Would you like to buy some shoes?",
"cars","All of these cars are nicer than Al Bundy's dodge",
"street","A busy, pothole infested Chicago street",
});
dest_dir = ({
"/players/jenny/bundy/rooms/5e","west",
 "/players/jenny/bundy/rooms/7e","east",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
