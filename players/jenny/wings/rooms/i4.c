inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("brown"))  {
if(random(100) < 35) {
MOCO("/players/jenny/wings/mobs/players/brown.c"),TO); }}
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice the ceiling is damaged."+NORM);
     set_smell(BOLD+"This corridor has a musty smell."+NORM);
long_desc=
"This narrow, musty corridor runs from the ice surface to\n"+      
"the player's facilities.  The white tile walls look very clean.\n"+
"The grey cement floor looks clean as well, despite years of\n"+
"use.  The ceiling tiles above you are noticeably damaged.\n"+
"There are doors to the north and south.\n";
items = ({
"ceiling","The white ceiling tiles have been noticeably damaged.  The\n"+
              "Russian players did this while warming up for a game by\n"+
               "kicking a soccer ball around",
"doors","There are closed metal doors to the north and south.  You could\n"+
             "probably enter your door of choice by going in that direction",
"door","There are closed metal doors to the north and south.  You could\n"+
             "probably enter your door of choice by going in that direction",
"walls","The walls are made of white tile.  They look like they have been\n"+
              "washed recently.  It gives the corridor a very cold feel",
"floor","The floor is made of cement.  The grey color adds to the cold\n"+
             "feel of the corridor",
});

dest_dir = ({
"/players/jenny/wings/rooms/i3","west",
"/players/jenny/wings/rooms/i5","east",
});
}
short() {
return BOLD+WHT+"A corridor"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("north","north");
add_action("south","south");
}
south() {
TP->move_player("into the referees room#players/jenny/wings/rooms/ref.c");
return 1; }
north() {
TP->move_player("into the meeting room#players/jenny/wings/rooms/meeting.c");
return 1; }
