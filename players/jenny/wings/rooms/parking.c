inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int whichplayer;
realm() { return "NT"; }
reset(arg) {
   whichplayer = random(100);
   if(!present("player"))  {
      if(whichplayer < 80) {
      MOCO("/players/jenny/wings/mobs/players/lidstrom.c"),TO);}

      if(whichplayer > 79) {
      MOCO("/players/jenny/wings/mobs/players/devereaux.c"),TO);}}
    if(arg) return;
    set_light(1);
set_smell(BOLD+"It smells like auto exhaust."+NORM);
set_listen(BOLD+"You can hear the traffic from the nearby street."+NORM);
long_desc=
"This is a parking lot outside of Joe Louis Arena that is reserved for\n"+
"Red Wing players, coaches, and management.  It is new black-top,\n"+
"with about 80 parking spaces.  A door leads into Joe Louis Arena,\n"+ 
"and the parking lot exits into the street, right next to the guard shack.\n"; 
items = ({
"street","The street leads out into the city of Detroit.  You could 'explore'\n"+
              "the 'city'",
"black-top","The parking lot is made up of new black-top.  There are a about\n"+
                "80 parking spaces",
"parking spaces","These are yellow lines painted into the black-top for cars to\n"+
                    "park between",
"shack","A small guard shack, with a guard inside.  It is here to keep the players\n"+
             "parking lot safe",
"guard","A large black man wearing a blue security guard uniform",
"arena","This is Joe Louis Arena.  It is a large building where the Detroit Red\n"+
             "Wings play hockey.  There is a door leading inside",
"spaces","These are yellow lines painted onto the black-top for cars to\n"+
"park between",
"door","A metal door leading into Joe Louis Arena.  It could be entered",
});
}
short() {
return BOLD+WHT+"Parking Lot"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
   add_action("arena","enter");
   add_action("detroit","explore");
}
arena(arg) {
if(arg == "door" || arg == "the door" || arg == "arena") {
TP->move_player("into Joe Louis Arena#players/jenny/wings/rooms/i5.c");
return 1;}}
detroit(arg) {
if(arg == "the city" || arg == "city" || arg == "detroit" || arg == "street") {
TP->move_player("into the street#players/pathfinder/detroit/rooms/city1.c");
return 1;}}
