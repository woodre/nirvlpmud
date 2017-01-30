inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("fan"))  {
if(!random(5)) {
MOCO("/players/jenny/wings/mobs/other/ffan.c"),TO); }}
    if(arg) return;
    set_light(1);
     set_listen(BOLD+"You can hear some activity down on the ice surface."+NORM+"\n");
     set_smell(BOLD+"You can smell food to the north."+NORM+"\n");
     set_search(BOLD+"You notice mens and womens restrooms along the wall."+NORM+"\n");
long_desc=
"You are standing in a concourse which wraps around the Joe\n"+      
"Louis Arena ice surface.  Before games, and between periods\n"+
"it is absolutely packed with fans, but it is relatively empty\n"+
"now.  Looking around the concourse, you notice an almost\n"+
"endless amount of concession stands.  There are mens and\n"+
"womens restrooms along the wall.\n";

items = ({
"concourse","This is a walkway which winds around Joe Louis Arena.  It exits\n"+
                    "into the stands.  Many concession stands, as well as souvenir shops\n"+
                    "are located within the concourse",
"ice surface","You can get a more clear view of this from the stands",
"restrooms","These are two of the bathrooms in Joe Louis Arena.  The arena has\n"+
                    "a shortage of restrooms, so there can be quite a wait sometimes",
"concession stands","You see many concession stands, which sell pizza, beer, coke, etc.\n"+
                                 "They do not appear to be open yet",
"stands","You see many concession stands, which sell pizza, beer, coke, etc\n"+
               "They do not appear to be open yet",
});

dest_dir = ({
 "/players/jenny/wings/rooms/c7","north",
"/players/jenny/wings/rooms/c5","east",
});
}
short() {
return BOLD+RED+"Joe Louis Arena concourse"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
