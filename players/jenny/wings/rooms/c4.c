inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("fan"))  {
if(!random(4)) {
MOCO("/players/jenny/wings/mobs/other/mfan.c"),TO); }}
    if(arg) return;
    set_light(1);
     set_listen(BOLD+"You can hear some activity down on the ice surface."+NORM+"\n");
     set_smell(BOLD+"You can smell food in the distance."+NORM+"\n");
     set_search(BOLD+"You notice mens and womens restrooms along the wall."+NORM+"\n");
long_desc=
"You are standing in a concourse which wraps around the Joe\n"+      
"Louis Arena ice surface.  Before games, and between periods\n"+
"it is absolutely packed with fans, but it is relatively empty\n"+
"now.  Looking around the concourse, you notice an almost\n"+
"endless amount of concession stands.  There are mens and\n"+
"womens restrooms along the wall, as well as a door with an\n"+
"exit sign above it.\n";

items = ({
"concourse","This is a walkway which winds around Joe Louis Arena.  It exits\n"+
                    "into the stands.  Many concession stands, as well as souvenir shops\n"+
                    "are located within the concourse",
"ice surface","You can get a more clear view of this from the stands",
"sign","The sign reads "+RED+"EXIT"+NORM+"",
"door","This door leads to a stairwell.  You could enter the door and\n"+
             "use the stairs",
"restrooms","These are two of the bathrooms in Joe Louis Arena.  The arena has\n"+
                    "a shortage of restrooms, so there can be quite a wait sometimes",
"concession stands","You see many concession stands, which sell pizza, beer, coke, etc.\n"+
                                 "They do not appear to be open yet",
"stands","You see many concession stands, which sell pizza, beer, coke, etc\n"+
               "They do not appear to be open yet",
});

dest_dir = ({
 "/players/jenny/wings/rooms/c3","north",
"/players/jenny/wings/rooms/c5","west",
});
}
short() {
return BOLD+RED+"Joe Louis Arena concourse"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("stairwell","enter");
}
stairwell(arg) {
if(!arg) {return 0;}
if(arg == "stairwell" || arg == "door" || arg == "the door" || arg == "the stairwell") {
TP->move_player("through the door#players/jenny/wings/rooms/stairs1.c");
return 1; }
}
