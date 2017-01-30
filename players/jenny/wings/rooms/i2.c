inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int inuse, door;
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice the ceiling is damaged."+NORM);
     set_smell(BOLD+"This corridor has a musty smell."+NORM);
     set_listen(BOLD+"You hear some activity coming from the ice surface."+NORM);
long_desc=
"This narrow, musty corridor runs from the ice surface to\n"+      
"the player's facilities.  The white tile walls look very clean.\n"+
"The grey cement floor looks clean as well, despite years of\n"+
"use.  The ceiling tiles above you are noticeably damaged.\n"+
"On one side of the hall, there is a door leading to a stairwell,\n"+
"an elevator, with a button next to it, is on the other side.\n";
items = ({
"ceiling","The white ceiling tiles have been noticeably damaged.  The\n"+
              "Russian players did this while warming up for a game by\n"+
               "kicking a soccer ball around",
"door","This is a door leading to a stairwell.  You could enter the door\n"+
             "and use the stairs",
"walls","The walls are made of white tile.  They look like they have been\n"+
              "washed recently.  It gives the corridor a very cold feel",
"floor","The floor is made of cement.  The grey color adds to the cold\n"+
             "feel of the corridor",
"elevator","This is an elevator which can take you up to the concourse,\n"+
               "media area, and suits.  You can enter the elevator",
"button","A red plastic button, you can push it to get the elevator",
});

dest_dir = ({
"/players/jenny/wings/rooms/i1","west",
"/players/jenny/wings/rooms/i3","east",
});
}
short() {
return BOLD+WHT+"A corridor"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
   add_action("stairwell","enter");
   add_action("button","push");
   add_action("button","press");
   add_action("elevator","enter");
}
stairwell(arg) {
if(!arg) {return 0;}
if(arg == "stairwell" | arg == "door") {
TP->move_player("through the door#players/jenny/wings/rooms/stairsb.c");
return 1; }
}
button(arg) {
if(!arg) { notify_fail("What do you want to push?\n"); }
if(arg == "button") {
if(inuse > 1) { write("The elevator is currently in use.  Try again in a few seconds.\n"); return 1;}
write("You push the button.\n");
call_out("button2",4);
inuse = 5;
call_other("/players/jenny/wings/rooms/s1.c","inuse");
call_other("/players/jenny/wings/rooms/2h8.c","inuse");
call_other("/players/jenny/wings/rooms/c2.c","inuse");
call_other("/players/jenny/wings/rooms/elevator.c","setbusy");
tell_room("/players/jenny/wings/rooms/elevator.c","The elevator doors close and it starts to move.\n");
return 1; }} 
button2() {
   tell_room("/players/jenny/wings/rooms/elevator.c","The elevator doors open.\n");
   tell_room("/players/jenny/wings/rooms/i2.c","The elevator doors open.\n");
   call_other("/players/jenny/wings/rooms/elevator.c","setfloor1");
call_other("/players/jenny/wings/rooms/i2.c","inuse2");
call_other("/players/jenny/wings/rooms/c2.c","inuse2");
call_other("/players/jenny/wings/rooms/s1.c","inuse2");
call_other("/players/jenny/wings/rooms/2h8.c","inuse2");
   door = 3;
   return 1; }
elevator(arg) {
  if(arg == "elevator" || arg == "the elevator") {
if(door < 1) {
write("The elevator doors are closed.\n");
return 1;}
TP->move_player("into the elevator#players/jenny/wings/rooms/elevator.c");
return 1; }}
inuse() {
inuse = 5;
return 1; }
door() {
door = 0;
return 1;}
inuse2() {
inuse = 0;
return 1;}
