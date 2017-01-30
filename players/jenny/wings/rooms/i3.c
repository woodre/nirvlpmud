inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice the ceiling is damaged."+NORM);
     set_smell(BOLD+"This corridor has a musty smell."+NORM);
long_desc=
"This narrow, musty corridor runs from the ice surface to\n"+      
"the player's facilities.  The white tile walls look very clean.\n"+
"The grey cement floor looks clean as well, despite years of\n"+
"use.  The ceiling tiles above you are noticeably damaged.\n"+
"The fitness room is to the north, and the wings locker\n"+
"room is to the south.\n";
items = ({
"ceiling","The white ceiling tiles have been noticeably damaged.  The\n"+
              "Russian players did this while warming up for a game by\n"+
               "kicking a soccer ball around",
"fitness room","The doors leading to the fitness room are to the north.\n"+
             "You could enter the fitness room and check it out",
"walls","The walls are made of white tile.  They look like they have been\n"+
              "washed recently.  It gives the corridor a very cold feel",
"floor","The floor is made of cement.  The grey color adds to the cold\n"+
             "feel of the corridor",
"locker room","The doors leading to the Red Wings locker room are to the south.\n"+
               "You could enter the locker room",

});

dest_dir = ({
"/players/jenny/wings/rooms/i2","west",
"/players/jenny/wings/rooms/i4","east",
});
}
short() {
return BOLD+WHT+"A corridor"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("fitness","enter");
add_action("north","north");
add_action("locker","enter");
add_action("south","south");
}

fitness(arg) {
if(!arg) {return 0;}
if(arg == "fitness room" | arg == "the fitness room") {
TP->move_player("into the fitness room#players/jenny/wings/rooms/fit1.c");
return 1; }}
locker(arg) {
if(!arg) {return 0;}
if(arg == "locker room" | arg == "the locker room") {
TP->move_player("into the locker room#players/jenny/wings/rooms/locker1.c");
return 1; }}
south() {
TP->move_player("into the locker room#players/jenny/wings/rooms/locker1.c");
return 1; }
north() {
TP->move_player("into the fitness room#players/jenny/wings/rooms/fit1.c");
return 1; }
