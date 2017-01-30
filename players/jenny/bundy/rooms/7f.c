inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
    if(arg) return;
    set_light(1);
     set_search(""+BOLD+"You find the mall doors.  Why not enter and look around?"+NORM+"\n");
     set_smell(""+BOLD+"You gag at the smell of exhaust fumes."+NORM+"\n");
short_desc=("A mean Chicago street.");
long_desc=
"This is the parking lot of a Chicago Mall.  There are cars\n"+
"parked all around you.  You can even see Al Bundy's Dodge.\n"+
"People are coming and going from the mall.\n";

items = ({
"cars","All of these cars are nicer than Al Bundy's Dodge",
"mall","A good sized mall that you could enter",
"people","All of these people make more money than Al Bundy",
"doors","These doors lead into the mall.  You could enter them",
"dodge",""+RED+
"This is a real American car.  They don't make them like\n"+
"this anymore.  Al has put a lot of miles on this baby.  This\n"+
"car used to be brown, but when it was finally washed, its\n"+
"true color was uncovered.  RED."+NORM+"\n",
});
dest_dir = ({
"/players/jenny/bundy/rooms/7e","north",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("mall","enter");
}
mall(arg) { 
if(!arg) { return 0; }
if(arg == "mall" | arg == "doors")  {
TP->move_player("into the mall#players/jenny/bundy/rooms/m3a.c");
return 1; }
}
