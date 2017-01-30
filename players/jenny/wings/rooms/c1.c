inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("fan"))  {
if(!random(6)) {
MOCO("/players/jenny/wings/mobs/other/mfan.c"),TO); }}
    if(arg) return;
    set_light(1);
     set_listen(BOLD+"You can hear some activity down on the ice surface."+NORM+"\n");
     set_smell(BOLD+"You can smell food nearby."+NORM+"\n");
long_desc=
"You are standing in a concourse which wraps around the Joe\n"+      
"Louis Arena ice surface.  Before games, and between periods\n"+
"it is absolutely packed with fans, but it is relatively empty\n"+
"now.  Looking around the concourse, you notice an almost\n"+
"endless amount of concession stands.  There is an exit to the\n"+
"north, while the doors to the south lead into the stands.\n";

items = ({
"concourse","This is a walkway which winds around Joe Louis Arena.  It exits\n"+
                    "into the stands.  Many concession stands, as well as souvenir shops\n"+
                    "are located within the concourse",
"ice surface","You can get a more clear view of this from the stands",
"concession stands","You see many concession stands, which sell pizza, beer, coke, etc.\n"+
                                 "They do not appear to be open yet",
"stands","You see many concession stands, which sell pizza, beer, coke, etc\n"+
               "They do not appear to be open yet",
"doors","These doors lead into the stands.  They are wide open",
});

dest_dir = ({
"/players/jenny/wings/rooms/stands1c1","south",
 "/players/jenny/wings/rooms/c8","west",
"/players/jenny/wings/rooms/c2","east",
 "/players/jenny/areaentrance","exit",
});
}
short() {
return BOLD+RED+"Joe Louis Arena concourse"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
