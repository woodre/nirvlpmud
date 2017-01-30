inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
     set_listen(""+BOLD+"You hear the buzzing of traffic."+NORM+"\n");
     set_smell(""+BOLD+"You gag at the smell of exhaust fumes."+NORM+"\n");
short_desc=("A mean Chicago street.");
long_desc=
"You are on a busy street in Chicago.  Traffic is very heavy\n"+
"here.  The entrance to the mall parking lot is to the south.\n"+
"cars are driving recklessly all around you.  This is Chicago\n"+
"traffic at its worst.\n";
items = ({
"parking lot","This is where the mall patrons and workers park their cars",
"cars","All of these cars are nicer than Al Bundy's dodge",
"street","A busy, pothole infested Chicago street",
});
dest_dir = ({
"/players/jenny/bundy/rooms/6e","west",
 "/players/jenny/bundy/rooms/7f","south",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
